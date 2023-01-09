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
    bool isProcessed(TreeNode* node, set<TreeNode*>&processed){
      if((node->left == nullptr || processed.count(node->left)) && (node->right == nullptr || processed.count(node->right)))
        return true;
      return false;
    }
    vector<int> postorderTraversal(TreeNode* root) {
      set<TreeNode*>processed;
      stack<TreeNode*>st;
      pushLeft(root, st);
      vector<int>ret;
      while(st.size()){
        TreeNode* top = st.top();
        if(isProcessed(top, processed)){
          ret.push_back(top->val);
          st.pop();
          processed.insert(top);
          continue;
        }
        pushLeft(top->right, st);
      }
      return ret;
    }
};