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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>ans;
      vector<TreeNode*> currNodes;
      if(root == nullptr)
        return ans;
      currNodes.push_back(root);
      while(currNodes.size()){
        vector<TreeNode*> nextNodes;
        vector<int>currVals;
        for(auto node:currNodes){
          currVals.push_back(node->val);
          if(node->left)
            nextNodes.push_back(node->left);
          if(node->right)
            nextNodes.push_back(node->right);
        }
        ans.push_back(currVals);
        currNodes = nextNodes;
      }
      return ans;
    }
};