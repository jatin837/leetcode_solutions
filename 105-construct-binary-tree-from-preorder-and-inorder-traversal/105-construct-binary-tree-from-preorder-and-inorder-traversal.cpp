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
    int indx=0;
    TreeNode* buildTree(vector<int>&preorder, vector<int>&inorder, unordered_map<int, int>& inorderIndx, int l, int r){
      if(l > r or l < 0 or r >= preorder.size())
        return nullptr;
      int rootVal = preorder[indx++];
      TreeNode* root = new TreeNode(rootVal);
      root->left = buildTree(preorder, inorder, inorderIndx, l, inorderIndx[rootVal]-1);
      root->right = buildTree(preorder, inorder, inorderIndx, inorderIndx[rootVal]+1, r);
      return root;
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int, int> inorderIndx;
      for(int i=0; i<inorder.size(); i++)
        inorderIndx[inorder[i]] = i;
      return buildTree(preorder, inorder, inorderIndx, 0, inorder.size()-1);
    }
};