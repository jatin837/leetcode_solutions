class Solution {
public:
  int ret = INT_MIN;
  void dfs(TreeNode* root, int mn, int mx){
    if(root){
      mn = min(root->val, mn);
      mx = max(root->val, mx);
      ret = max(ret, abs(mx-mn));
      dfs(root->left, mn, mx);
      dfs(root->right, mn, mx);
    }
  }
  int maxAncestorDiff(TreeNode* root) {
    dfs(root, root->val, root->val);
    return ret;
  }
};