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
    vector<int> inorderTraversal(TreeNode* root) {
      if(root==nullptr)
        return {};
      vector<int>ret;
      for(auto n:inorderTraversal(root->left))
        ret.push_back(n); 
      ret.push_back(root->val);
      for(auto n:inorderTraversal(root->right))
        ret.push_back(n); 
      return ret;
    }
};