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
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      vector<double>ret;
      while(!q.empty()){
        queue<TreeNode*> tmp;
        double sum=0;
        int cnt=0;
        while(!q.empty()){
          TreeNode* top = q.front();
          q.pop();
          if(top==nullptr)
            continue;
          cnt++;
          sum += top->val;
          tmp.push(top->left);
          tmp.push(top->right);
        }
        if(cnt) ret.push_back(sum/cnt);
        q=tmp;
      }
      return ret;
    }
};