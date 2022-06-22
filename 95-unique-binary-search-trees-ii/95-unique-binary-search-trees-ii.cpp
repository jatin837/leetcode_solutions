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
    vector<TreeNode*> backtrack(int start, int end){
      if(start > end)
        return {nullptr};
      vector<TreeNode*> ans;
      for(int i=start; i<=end; i++){
        auto ls = backtrack(start, i-1);
        auto rs = backtrack(i+1, end);
        for(auto r:rs){
          for(auto l:ls){
            TreeNode* curr = new TreeNode(i);
            curr->left = l;
            curr->right = r;
            ans.push_back(curr);
          }
        }
      }
      return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
      return backtrack(1, n);
    }
};