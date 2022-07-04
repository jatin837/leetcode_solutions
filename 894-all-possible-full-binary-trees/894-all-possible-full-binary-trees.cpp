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
    array<vector<TreeNode*>, 22> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
      if(n%2){
        vector<vector<TreeNode*>> dp(40);
        TreeNode* root = new TreeNode(0);
        dp[1] = {root};
        for(int i=3; i<=n; i+=2){
          int j = 1;
          int k = i-2;
          while(j < i and k > 0){
            for(auto l:dp[j])
              for(auto r:dp[k])
                dp[i].push_back(new TreeNode(0, l, r));
            k-=2;
            j+=2;
          }
        }
        return dp[n];
      }
      return {};
    }
};