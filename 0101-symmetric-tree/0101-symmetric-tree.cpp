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
    bool isSymmetric(TreeNode* root) {
         queue<TreeNode*> left;
         queue<TreeNode*> right;
         if(root->left) left.push(root->left);
         if(root->right) right.push(root->right);
         while(!left.empty() && !right.empty()){
            TreeNode* ltemp = left.front();
            TreeNode* rtemp = right.front();
            left.pop();
            right.pop();
            if(ltemp->left && !rtemp->right)
                return false;
            if(!ltemp->left && rtemp->right)
                return false;
            if(ltemp->right && !rtemp->left)
                return false;
            if(!ltemp->right && rtemp->left)
                return false;    

            if(ltemp->left)left.push(ltemp->left);
            if(ltemp->right) left.push(ltemp->right);
            if(rtemp->right) right.push(rtemp->right);
            if(rtemp->left) right.push(rtemp->left);
            if(ltemp->val != rtemp->val){
                return false;
            }
         }

         if(!left.empty() || !right.empty())
            return false;
         return true;    
    }
};