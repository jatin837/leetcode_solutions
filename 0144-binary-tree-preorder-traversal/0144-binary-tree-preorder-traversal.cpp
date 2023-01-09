class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int>ret;
      stack<TreeNode*>st;
      st.push(root);
      if(root == nullptr)
        return ret;
      while(st.size()){
        TreeNode* top = st.top();
        st.pop();
        ret.push_back(top->val);
        if(top->right) st.push(top->right);
        if(top->left) st.push(top->left);
      }
      return ret;
    }
};