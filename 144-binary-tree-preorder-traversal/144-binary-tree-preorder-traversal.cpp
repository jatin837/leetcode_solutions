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
    vector<int> ans;
    void solve(TreeNode* root, vector<int>&nums){
      if(root == nullptr)
        return;
      nums.push_back(root->val);
      if(root->left)
        solve(root->left, ans);
      if(root->right)
        solve(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
      solve(root, ans); 
      return ans;
    }
};