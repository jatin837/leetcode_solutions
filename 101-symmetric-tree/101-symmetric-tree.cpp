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
    bool compare(TreeNode* left, TreeNode* right){
      if (left == nullptr and right == nullptr)
        return true;
      if(left and right){
        if(left->val == right->val){
          bool outside = compare(left->left, right->right);
          bool inside = compare(right->left, left->right);
          return outside and inside;
        }
      }
      return false;
    } 
  
    bool isSymmetric(TreeNode* root) {
      return compare(root->left, root->right);
    }
};