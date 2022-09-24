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
  vector<vector<int>>ret; 
  void dfs(vector<int>tmp, int sum, int targetSum, TreeNode* node){
    sum += node->val;
    tmp.push_back(node->val);
    if(node->left)
      dfs(tmp, sum, targetSum, node->left);
    if(node->right)
      dfs(tmp, sum, targetSum, node->right);
    if(node->left == nullptr && node->right == nullptr)
      if(sum == targetSum)
        ret.push_back(tmp);
  }
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(root)
      dfs({}, 0, targetSum, root);
    return ret;
  }
};