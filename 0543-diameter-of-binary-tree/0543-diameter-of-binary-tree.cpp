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
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        return max(lHeight, rHeight) + 1;
    }

    void solve(TreeNode* root, int &h){
        if(root == nullptr)
            return;
        int left = height(root->left);
        int right = height(root->right);
        int total = left + right;
        if(total > h)
            h = total;
        solve(root->left, h);
        solve(root->right, h);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        solve(root, h);
        return h;
    }
};