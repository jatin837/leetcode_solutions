class Solution {
public:
  bool bfs(int node, vector<int>&col, vector<vector<int>>&G){
    col[node] = 1;
    queue<int>q;
    q.push(node);
    while(q.size()){
      int node = q.front();
      q.pop();
      int nextColr = (col[node] == 1)?2:1;
      for(int next:G[node]){
        if(col[next] == 0){
          q.push(next);
          col[next] = nextColr;
        }else if(col[next] != nextColr)
          return false;
      }
    }
    return true;
  }
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<int>col(n+1, 0);
    vector<vector<int>>G(n+1);
    queue<int>q;
    for(vector<int>d:dislikes){
      int a = d[0], b = d[1];
      G[a].push_back(b),G[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
      if(col[i] == 0){
        if(bfs(i, col, G) == false)
          return false;
      }
    }
    return true;
  }
};