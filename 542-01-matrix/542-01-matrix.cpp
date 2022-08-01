#define G vector<vector<int>>
#define P pair<int, int>
class Solution {
public:
vector<pair<int, int>> dd = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> updateMatrix(vector<vector<int>>& M){
  queue<array<int, 3>>q;
  for(int i=0; i<M.size(); i++)
    for(int j=0; j<M[0].size(); j++){
      if(!M[i][j])
        q.push({i, j, 0});
      M[i][j]=-1;
    }
  while(!q.empty()){
    auto [x, y, curr] = q.front();
    q.pop();
    if(x < 0 || y < 0 || x >= M.size() || y >= M[0].size() || M[x][y] != -1)
      continue;
    M[x][y] = curr;
    for(auto [dx, dy]:dd)
      q.push({x+dx, y+dy, curr+1});
  }
  return M;
}
};