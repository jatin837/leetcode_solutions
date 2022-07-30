#define Pi pair<int, int>
#define G vector<vector<int>>
class Solution {
public:
    vector<pair<int, int>> dd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> pacificAtlantic(G& g) {
      queue<Pi>qA;
      queue<Pi>qP;
      vector<vector<int>>ans;
      int r = g.size(), c = g[0].size();
      for(int i=0; i<r; i++){
        qP.push({i, 0});
        qA.push({i, c-1});
      }
      for(int i=0; i<c; i++){
        qP.push({0, i});
        qA.push({r-1, i});
      }
      bool P[200][200] = {false}, A[200][200] = {false};
      bfs(qP, g, P);
      bfs(qA, g, A);
      for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
          if(P[i][j] and A[i][j])
            ans.push_back({i, j});
      return ans;
    }
    void bfs(queue<Pi>& q, G& g, bool visited[200][200]){
      while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        visited[x][y] = true;
        int prev = g[x][y];
        for(auto [dx, dy]:dd){
          if(x+dx < 0 || y+dy < 0 || x+dx >= g.size() || y+dy >= g[0].size() || visited[x+dx][y+dy] || g[x+dx][y+dy] < prev)
            continue;
          q.push({x+dx, y+dy});
        }
      }
    }
};