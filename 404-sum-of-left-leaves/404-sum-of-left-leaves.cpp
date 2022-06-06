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
    bool isLeaf(TreeNode* node){
      if(node == nullptr)
        return false;
      return node->left == nullptr and node->right == nullptr;
    }
    void dfs(TreeNode* root){
      if(root == nullptr)
        return;
      if(isLeaf(root))
        return;
      if(isLeaf(root->left))
        ans += root->left->val;
      
      dfs(root->left);
      dfs(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
      dfs(root);
      return ans;
    }
};