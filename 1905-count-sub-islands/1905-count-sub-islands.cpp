#define G vector<vector<int>>&
class Solution {
public:
vector<pair<int, int>>island;
void dfs(int r, int c, G g2){
  if(r<0 || c<0 || r >= g2.size() || c >= g2[0].size() || g2[r][c] == 0)
    return;
  g2[r][c]=0;
  island.push_back({r,c});
  dfs(r-1, c, g2);
  dfs(r+1, c, g2);
  dfs(r, c-1, g2);
  dfs(r, c+1, g2);
}
bool isSubIsland(G g1){
  for(auto [r, c]:this->island)
    if(g1[r][c]==0)
      return false;
  return true;
}
int countSubIslands(G g1, G g2) {
  int cnt = 0;
  for(int i=0; i<g1.size(); i++)
    for(int j=0; j<g1[0].size(); j++)
      if(g2[i][j]){
        dfs(i, j, g2);
        cnt += isSubIsland(g1);
        island.clear();
      }
  return cnt;
}
};