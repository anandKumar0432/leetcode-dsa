/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int position(vector<int> &inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode* construct(vector<int> &preorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = position(inorder, element, n);

        root->left = construct(preorder, inorder, index, inorderStart, pos-1, n);
        root->right = construct(preorder, inorder, index, pos+1, inorderEnd, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int n = inorder.size();
        int inorderStart = 0;
        int inorderEnd = n-1;
        TreeNode* res = construct(preorder, inorder, index, inorderStart, inorderEnd, n);
        return res;
    }
};