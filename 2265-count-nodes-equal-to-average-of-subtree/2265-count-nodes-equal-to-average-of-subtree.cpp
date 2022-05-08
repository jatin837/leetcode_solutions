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
    
    int ans = 0;
    pair<int, int> solve(TreeNode* root){
      if(root == nullptr)
        return {0, 0};
      auto left = solve(root->left);
      auto right = solve(root->right);
      
      int ls = left.second;
      int lcnt = left.first; 
      int rs = right.second;
      int rcnt = right.first;
      int sum = ls + rs + root->val;
      int cnt = lcnt + rcnt + 1;
      
      if (root->val == sum/cnt)
        ans++;
      return {cnt, sum};
    }
  
    int averageOfSubtree(TreeNode* root) {
      solve(root); 
      return ans;
    }
};