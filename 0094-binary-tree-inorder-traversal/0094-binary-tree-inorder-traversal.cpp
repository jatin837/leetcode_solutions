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
    void pushLeft(TreeNode* node, stack<TreeNode*>&st){
      while(node){
        st.push(node);
        node = node->left;
      }
    }
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode*>st;
      pushLeft(root, st);
      vector<int>ret;
      while(st.size()){
        TreeNode* top = st.top();
        st.pop();
        ret.push_back(top->val);
        pushLeft(top->right, st);
      }
      return ret;
    }
};