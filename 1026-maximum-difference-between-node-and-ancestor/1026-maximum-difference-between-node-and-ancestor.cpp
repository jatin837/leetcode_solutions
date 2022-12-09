class Solution {
public:
  int maxAncestorDiff(TreeNode* root) {
    stack<pair<TreeNode*, array<int, 2>>> st;
    st.push({root, {root->val, root->val}});
    int ret = 0;
    while(st.size()){
      auto top = st.top();
      TreeNode* node = top.first;
      st.pop();
      if(node){
        int mn = min(top.second[0], node->val);
        int mx = max(top.second[1], node->val);
        if(node->left || node->right)
          st.push({node->left, {mn, mx}}), st.push({node->right, {mn, mx}});
        else
          ret = max(ret, abs(mn-mx));
      }
    }
    return ret;
  }
};