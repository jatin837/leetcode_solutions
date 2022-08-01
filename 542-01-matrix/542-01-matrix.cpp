#define G vector<vector<int>>
#define P pair<int, int>
class Solution {
public:
    vector<pair<int, int>> dd = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& M){
      vector<vector<int>>dist = vector(M.size(), vector<int>(M[0].size(), -1));
      queue<P>q;
      for(int i=0; i<M.size(); i++)
        for(int j=0; j<M[0].size(); j++)
          if(!M[i][j])
            q.push({i, j});
      int curr = 0;
      while(!q.empty()){
        queue<P>tmp;
        while(!q.empty()){
          auto [x, y] = q.front();
          q.pop();
          if(x < 0 || y < 0 || x >= M.size() || y >= M[0].size() || dist[x][y] != -1)
            continue;
          dist[x][y] = curr;
          for(auto [dx, dy]:dd)
            tmp.push({x+dx, y+dy});
        }
        curr++;
        q = tmp;
      }
      return dist;
    }
};