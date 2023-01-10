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

/*
1 1
1 0
0 1
0 0
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p && q)
        return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
      if(!p && !q)
        return true;
      return false;
    }
};