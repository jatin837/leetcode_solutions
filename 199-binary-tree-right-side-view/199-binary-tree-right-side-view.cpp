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
    vector<int>ans;
    deque<TreeNode*> q;
    void bfs(vector<TreeNode*>depth){
      vector<TreeNode*> next;
      for(auto node:depth){
        if(node->left)
          next.push_back(node->left);
        if(node->right)
          next.push_back(node->right);
      }
      if(depth.size()){
        ans.push_back(depth.back()->val);
        bfs(next);
      }
    }
    vector<int> rightSideView(TreeNode* root) {
     if(root)
       ans.push_back(root->val);
     else
       return {};
     vector<TreeNode*>init;
     if(root->left)
       init.push_back(root->left); 
     if(root->right)
       init.push_back(root->right); 
     bfs(init); 
     return ans;
    }
};