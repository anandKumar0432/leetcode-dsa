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
 // ------------RECURSIVELY-----------
// class Solution {
// public:
//     void preorder(TreeNode* root, vector<int> &res){
//         if(root == nullptr){
//             return;
//         }
//         res.push_back(root->val);
//         preorder(root->left, res);
//         preorder(root->right, res);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         preorder(root, res);
//         return res;
//     }
// };

// ------------ITERATIVELY-------------
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);
            res.push_back(top->val);
        }
        return res;
    }
};