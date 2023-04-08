/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* mp[101] = {nullptr};
    Node* cloneGraph(Node* node) {
      if(node){
        if(mp[node->val])
          return mp[node->val];
        Node* newNode = new Node(node->val);
        mp[node->val] = newNode;
        for(auto n:node->neighbors)
          newNode->neighbors.push_back(cloneGraph(n));
        return newNode;       
      }
      return nullptr;
    }
};