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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      TreeNode* dummy = new TreeNode(-1, root, nullptr);
      dummy->left = addOneRow(dummy->left, val, depth-1, false);
      return dummy->left;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth, bool right) {
      if(depth == 0 && right){
        TreeNode* newRoot = new TreeNode(val, nullptr, root);
        return newRoot;
      }else if(depth == 0){
        TreeNode* newRoot = new TreeNode(val, root, nullptr);
        return newRoot;
      }
      if(root == nullptr)
        return nullptr;
      
      root->left = addOneRow(root->left, val, depth-1, false);
      root->right = addOneRow(root->right, val, depth-1, true);
      return root;
    }
};