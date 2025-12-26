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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        if(root == nullptr) return res;
        int j = 1;
        deque<TreeNode*> dq;
        dq.push_front(root);
        while(!dq.empty()){
            int size = dq.size();
            for(int i=0; i<size; i++){                
                if(j % 2 == 1){
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    if(node->left) dq.push_front(node->left);
                    if(node->right) dq.push_front(node->right);
                    level.push_back(node->val);
                }else{
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    if(node->right) dq.push_back(node->right);
                    if(node->left) dq.push_back(node->left);
                    level.push_back(node->val);
                }
            }
            res.push_back(level);
            level.clear();
            j++;
        }
        return res;
    }
};