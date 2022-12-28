class Solution {
public:
    bool isValidBST(TreeNode* root) {
      stack<pair<TreeNode*, array<long, 2>>>st;
      st.push({root, {LONG_MIN, LONG_MAX}});
      while(!st.empty()){
        auto node = st.top().first;
        auto [minVal, maxVal] = st.top().second;
        st.pop();
        if(node){
          if(node->val <= minVal || node->val >= maxVal)
            return false;
          st.push({node->left, {minVal, node->val}});
          st.push({node->right, {node->val, maxVal}});
        }
      }
      return true;
    }
};