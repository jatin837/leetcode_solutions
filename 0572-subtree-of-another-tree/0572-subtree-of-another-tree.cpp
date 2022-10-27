class Solution {
public:
  bool dfs(TreeNode* node1, TreeNode* node2){
    if(node1 == nullptr && node2 == nullptr)
      return true;
    if(node1 == nullptr || node2 == nullptr)
      return false;
    if(node1->val == node2->val)
      return dfs(node1->left, node2->left) && dfs(node1->right, node2->right);
    return false;
  }
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(dfs(root, subRoot))
      return true;
    if(root == nullptr && subRoot == nullptr)
      return true;
    if(root == nullptr || subRoot == nullptr)
      return false;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};