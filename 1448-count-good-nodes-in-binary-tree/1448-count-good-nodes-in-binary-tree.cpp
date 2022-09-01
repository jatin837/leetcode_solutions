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
    int cnt = 0;
    void dfs(TreeNode* root, int val){
      if(root==nullptr)
        return;
      if(root->val >= val){
        cnt++;
        dfs(root->left, root->val);
        dfs(root->right, root->val);
      }
      else{
        dfs(root->left, val);
        dfs(root->right, val);
      }
    }
    int goodNodes(TreeNode* root) {
      dfs(root, root->val);    
      return cnt;
    }
};