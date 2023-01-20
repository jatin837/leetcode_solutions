class Solution {
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>>G(n);
    set<vector<int>>conn(connections.begin(), connections.end());
    for(vector<int>e:connections)
      G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
    int cnt = 0;
    queue<pair<int, int>>q;
    q.push({0, -1});
    while(q.size()){
      auto [curr, parent] = q.front();
      q.pop();
      for(int c:G[curr]){
        if(c != parent){
          q.push({c, curr});
          if(conn.count({c, curr}) == 0){
            conn.insert({c,curr});
            conn.erase({curr,c});
            cnt++;
          }
        }
      }
    }
    return cnt;
  }
};