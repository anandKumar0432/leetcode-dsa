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

 // -------------Using recursion----------------
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int> & res){
//         if(root == nullptr){
//             return;
//         }
//         inorder(root->left, res);
//         res.push_back(root->val);
//         inorder(root->right, res);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inorder(root, res);
//         return res;
//     }
// };

// -----------Iteratively using one stack---------------
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         vector<int> inorder;
//         TreeNode* node = root;
//         while(true){
//             if(node != NULL){
//                 st.push(node);
//                 node = node->left;
//             }else{
//                 if(st.empty()) break;
//                 node = st.top();
//                 st.pop();
//                 inorder.push_back(node->val);
//                 node = node->right;
//             }
//         }
//         return inorder;
//     }
// };

// -------------Morris Order Traversal -----------------
class Solution {
public:

    TreeNode* predecessor(TreeNode* curr){
        TreeNode* pred = curr->left;
        while(pred->right != NULL && pred->right != curr){
            pred = pred->right;
        }
        return pred;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = predecessor(curr);
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};