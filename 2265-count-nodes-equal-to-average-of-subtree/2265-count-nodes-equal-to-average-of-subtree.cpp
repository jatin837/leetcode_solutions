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
    void printInorder(TreeNode* root){
      if (root == nullptr)
        return;
      this->printInorder(root->left);
      cout<<" "<<root->val<<" ";
      this->printInorder(root->right);
    }
    
    int sumInorder(TreeNode* root, int& cnt){
      if(root == nullptr)
        return 0;
      cnt++;
      int ls = sumInorder(root->left, cnt);
      int rs = sumInorder(root->right, cnt);
      return ls + rs + root->val;
    }
  
    void solve(TreeNode* root, int& ans){
      if (root == nullptr)
        return;
      int cnt = 0;
      int sum = sumInorder(root, cnt);
      int avg = sum/cnt;
      if (avg == root->val)
        ans++;
      solve(root->left, ans);
      solve(root->right, ans);
    }
  
    int averageOfSubtree(TreeNode* root) {
      int ans = 0;
      solve(root, ans);
      return ans;
    }
};