class Solution {
public:
  vector<TreeNode*>ret;
  unordered_map<string, int>cnt;
  string f(TreeNode* node){
    if(node == nullptr)
      return "";
    string l_string = "(" + f(node->left) + ")";
    string r_string = "(" + f(node->right) + ")";
    string curr_string =  l_string + "(" + to_string(node->val) + ")" + r_string;
    cnt[curr_string]++;
    if(cnt[curr_string] == 2)
      ret.push_back(node);
    return curr_string;
  }
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    f(root);
    return ret;
  }
};