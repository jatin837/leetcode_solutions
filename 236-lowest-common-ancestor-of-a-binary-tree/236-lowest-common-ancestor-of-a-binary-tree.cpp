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
    TreeNode* ans;
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q){
      if(node){
        int l = dfs(node->left, p, q)?1:0;
        int r = dfs(node->right, p, q)?1:0;
        int m = (node == p or node == q)?1:0;
        if(m+l+r >= 2)
          this->ans = node;
        return m+l+r>0;
      }
      return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      dfs(root, p, q);
      return ans;
    }
};