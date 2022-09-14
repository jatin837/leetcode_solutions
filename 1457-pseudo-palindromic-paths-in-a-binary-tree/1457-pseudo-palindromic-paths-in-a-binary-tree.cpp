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
    set<int>visited;
    int ans = 0;
    void backtrack(int cnt, TreeNode* node, int msk){
      if(node == nullptr)
        return;
      msk ^= 1<<(node->val);
      if(node->right == nullptr && node->left == nullptr){
        if((cnt+1)%2 == __builtin_popcount(msk))
          ans++;
        return;
      }
      backtrack(cnt+1, node->right, msk);
      backtrack(cnt+1, node->left, msk);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
      backtrack(0, root, 0);
      return ans;
    }
};