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
    TreeNode* pruneTree(TreeNode* root) {
      if(root==nullptr)
        return nullptr;
      TreeNode* rootLeft = pruneTree(root->left);
      TreeNode* rootRight = pruneTree(root->right);
      if(rootLeft==nullptr && rootRight==nullptr && root->val==0)
        return nullptr;
      root->right = rootRight;
      root->left = rootLeft;
      return root;
    }
};