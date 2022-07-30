#define G vector<vector<int>>
#define Pi pair<int, int>
class Solution {
public:
    vector<pair<int, int>> dd = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    int shortestPathBinaryMatrix(G& g) {
      queue<Pi>q; 
      int r = g.size(), c = g[0].size();
      if(g[0][0] || g[r-1][c-1])
        return -1;
      q.push({0, 0});
      int dist = 0;
      while(!q.empty()){
        queue<Pi>tmp; 
        dist++;
        while(!q.empty()){
          auto [x, y] = q.front(); 
          q.pop();
          if(x >= 0 && y >= 0 && x < r && y < c && !g[x][y]){
            g[x][y] = 1;
            if(x == r-1 && y == c-1) return dist;
            for(auto [dx, dy]:dd)
              tmp.push({x+dx, y+dy});
          }
        }
        q = tmp;
      }
      return -1;
    }
};