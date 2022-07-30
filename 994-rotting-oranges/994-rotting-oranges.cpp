#define Pi pair<int, int>
#define G vector<vector<int>>
class Solution {
public:
    int orangesRotting(G& g) {
      int t = 0;
      queue<Pi>q1;
      int r = g.size(), c = g[0].size();
      for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
          if(g[i][j]==2){
            q1.push({i-1, j});
            q1.push({i+1, j});
            q1.push({i, j-1});
            q1.push({i, j+1});
          }
        }
      }
      while(!q1.empty()){
        t++;
        queue<Pi>q2;
        while(!q1.empty()){
          auto [x, y] = q1.front();
          q1.pop();
          if(x < 0 || y < 0 || x >= r || y >= c || g[x][y] == 0 || g[x][y] == 2)
            continue;
          g[x][y] = 2;
          q2.push({x-1, y});
          q2.push({x+1, y});
          q2.push({x, y-1});
          q2.push({x, y+1});
        }
        q1 = q2;
      }
      int z = 0;
      for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
          if(g[i][j]==1)
            return -1;
          else if(g[i][j]==0)
            z++;
      if(z == r*c)
        return 0;
      return t-1;
    }
};