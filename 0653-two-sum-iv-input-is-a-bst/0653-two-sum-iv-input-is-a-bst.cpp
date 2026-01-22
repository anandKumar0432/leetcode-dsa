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
    void solve(TreeNode* root, int &k, set<int>& st, bool& res){
        if(root == nullptr){
            return;
        }
        solve(root->left, k, st, res);
        if(st.find(k - root->val) != st.end()){
            res = true;
            return;
        }else{
            st.insert(root->val);
        }
        solve(root->right, k, st, res);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        bool res = false;
        solve(root, k, st, res);
        return res;
    }
};