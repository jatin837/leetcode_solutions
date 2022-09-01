class Solution {
public:
    int cnt = 0;
    void bfs(TreeNode* root){
      queue<pair<TreeNode*, int>> q;
      q.push({root, root->val});
      while(!q.empty()){
        auto [node, val] = q.front();
        q.pop();
        if(node == nullptr)
          continue;
        if(node->val >= val){
          cnt++;
          q.push({node->left, node->val});
          q.push({node->right, node->val});
          continue;
        }
        q.push({node->left, val});
        q.push({node->right, val});
      }
    }
    int goodNodes(TreeNode* root) {
      bfs(root);    
      return cnt;
    }
};