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
    vector<int> preorderTraversal(TreeNode* root) {
      if(root == nullptr)
        return {};
      vector<int>a = preorderTraversal(root->left);
      vector<int>b = preorderTraversal(root->right);
      vector<int>ret = {root->val};
      for(int n:a)
        ret.push_back(n);
      for(int n:b)
        ret.push_back(n);
      return ret;
    }
};