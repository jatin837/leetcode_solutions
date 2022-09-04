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
    map<int, map<int, vector<int>>>mp;
    void dfs(int c, int r, TreeNode* root){
      if(root == nullptr)
        return;
      mp[c][r].push_back(root->val);
      dfs(c-1, r+1, root->left);
      dfs(c+1, r+1, root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      dfs(0, 0, root);
      vector<vector<int>>ans;
      for(auto [c, r]:mp){
        vector<int>tmp;
        for(auto [_, v]:r){
          sort(v.begin(), v.end());
          for(int n:v)
            tmp.push_back(n);
        }
        ans.push_back(tmp);
      }
      return ans;
    }
};