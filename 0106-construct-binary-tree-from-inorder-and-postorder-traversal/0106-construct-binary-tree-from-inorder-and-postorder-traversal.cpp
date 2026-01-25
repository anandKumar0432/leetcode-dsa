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
    int position(vector<int>& inorder, int n, int element){
        for(int i=0; i<n; i++){
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int pos = position(inorder, n, element);

        root->right = construct(inorder, postorder, index, pos+1, inorderEnd, n);
        root->left = construct(inorder, postorder, index, inorderStart, pos-1, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n-1;
        int inorderStart = 0;
        int inorderEnd = n-1;
        TreeNode* res = construct(inorder, postorder, index, inorderStart, inorderEnd, n);
        return res;
    }
};