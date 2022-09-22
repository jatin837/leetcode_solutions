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
    int ret = INT_MIN;
    int dfs(TreeNode* node){
      if(node == nullptr)
        return 0;
      int max_right = dfs(node->right);
      int max_left = dfs(node->left);
      int curr_path_sum = max(max_right, 0) + max(max_left, 0) + node->val;
      ret = max(curr_path_sum, ret);
      return node->val + max({0, max_right, max_left});
    }
    int maxPathSum(TreeNode* root) {
      dfs(root);
      return ret;
    }
};