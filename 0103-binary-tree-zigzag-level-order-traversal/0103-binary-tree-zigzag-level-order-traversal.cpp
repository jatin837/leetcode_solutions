class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if(root == nullptr)
        return {};
      vector<vector<int>> ret;
      vector<TreeNode*>curr;
      vector<TreeNode*>next;
      curr.push_back(root);
      while(curr.size()){
        vector<int>tmp;
        for(auto node:curr){
          tmp.push_back(node->val);  
          if(node->left)
            next.push_back(node->left);
          if(node->right)
            next.push_back(node->right);
        }
        curr.clear();
        curr = next;
        next.clear();
        ret.push_back(tmp);
      }
      int i=1;
      while(i<ret.size()){
        reverse(ret[i].begin(), ret[i].end());
        i+=2;
      }
      return ret;
    }
};