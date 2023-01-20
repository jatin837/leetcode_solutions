class Solution {
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    
    // build an undirected graph
    // maintain a status of connection between nodes
    // we can use a bool to denote a connection between nodes
    vector<vector<pair<int, bool>>>G(n);
    for(vector<int>e:connections)
      G[e[0]].push_back({e[1],true}),
        G[e[1]].push_back({e[0], false});
    
    // finally, do a bfs and count the number of connection from parent to child
    // basically, these are the connections we need to invert (child should point to parent)
    int cnt = 0;
    queue<pair<int, int>>q;
    q.push({0, -1});
    
    while(q.size()){
      auto [curr, parent] = q.front();
      q.pop();
      for(auto [c, conn]:G[curr]){
        if(c != parent){
          q.push({c, curr});
          cnt += conn;
        }
      }
    }
    
    return cnt;
  }
};