/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if(root==nullptr)
        return nullptr;
      vector<Node*>curr, next;
      curr.push_back(root);
      while(curr.size()){
        for(int i=0; i<curr.size()-1;i++){
          curr[i]->next = curr[i+1];
          if(curr[i]->left) next.push_back(curr[i]->left);
          if(curr[i]->right) next.push_back(curr[i]->right);
        }
        if(curr.back()->left) next.push_back(curr.back()->left);
        if(curr.back()->right) next.push_back(curr.back()->right);
        curr.clear();
        curr = next;
        next.clear();
      }
      return root;
    }
};