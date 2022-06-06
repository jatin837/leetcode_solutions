/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      int lrg = max(p->val, q->val);
      int sml = min(q->val, p->val);
      if(root->val < sml)
        return lowestCommonAncestor(root->right, p, q);
      if(root->val > lrg)
        return lowestCommonAncestor(root->left, p, q);
      return root;
    }
};