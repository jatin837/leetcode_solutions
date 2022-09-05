/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>>ret;
    if(root){
      queue<Node*>curr;
      curr.push(root);
      while(curr.size()){
        queue<Node*>next;
        ret.push_back({});
        while(curr.size()){
          Node* top = curr.front();
          ret.back().push_back(top->val);
          curr.pop();
          for(auto child:top->children)
            next.push(child);
        }
        curr = next;
      }  
    }
    
    return ret;
  }
};