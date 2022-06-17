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
    array<int, 3> solve(TreeNode* root){
      if(root == nullptr)
        return {0, 0, 99999};
      array<int, 3> left = solve(root->left);
      array<int, 3> right = solve(root->right);
      int mL12 = min(left[1], left[2]);
      int mR12 = min(right[1], right[2]);
      int d0 = left[1] + right[1];
      int d1 = min(left[2] + mR12, right[2] + mL12);
      int d2 = 1+min(left[0], mL12) + min(right[0], mR12);
      return {d0, d1, d2};
    }
    int minCameraCover(TreeNode* root) {
      array<int, 3> ans = solve(root);
      return min(ans[1], ans[2]);
    }
};