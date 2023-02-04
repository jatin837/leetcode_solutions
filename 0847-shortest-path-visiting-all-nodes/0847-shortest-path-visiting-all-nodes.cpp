// path -> [currNode, visitedPath, cost]
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    queue<array<int, 3>>q;
    bool visited[4096][12];
    memset(visited, false, sizeof(visited));
    int ret = INT_MAX;
    for(int i=0; i<graph.size(); i++)
      q.push({i, 0, 0}),visited[1<<i][i]=true;
    while(q.size()){
      int sz = q.size();
      while(sz--){
        auto p = q.front();
        int currNode = p[0];
        int visitedPath = p[1];
        int cost = p[2];
        q.pop();
        if(__builtin_popcount(visitedPath) == graph.size())
          ret = min(ret, cost-1);
        visitedPath = visitedPath | (1<<currNode);
        for(int n:graph[currNode])
          if(!visited[visitedPath][n]){
            q.push({n, visitedPath, cost+1});
            visited[visitedPath][n] = true;
          }
      }
    }
    return (ret == INT_MAX)?0:ret;
  }
};