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
    void levelOrder(TreeNode* root,vector<vector<int>> &ans) {
            if(root == nullptr) return;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int size = q.size();
                vector<int> level;
                for(int i=0; i<size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                    level.push_back(node->val);
                }
                ans.push_back(level);
            }
        }
    vector<int> rightSideView(TreeNode* root) {
         vector<vector<int>> res;
         levelOrder(root, res);
         vector<int> rightView;
         for(int i=0; i<res.size(); i++){
            rightView.push_back(res[i][res[i].size() - 1]);
         }
         return rightView;
    }
};