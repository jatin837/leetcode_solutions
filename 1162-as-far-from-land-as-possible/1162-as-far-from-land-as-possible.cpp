#define G vector<vector<int>>&
class Solution {
public:
  int maxDistance(G g) {
    int r = g.size();
    int c = g[0].size();
    queue<pair<int, int>>q1;
    for(int i=0; i<r; i++){
       for(int j=0; j<c; j++){
         if(g[i][j]){
          q1.push({i-1, j});
          q1.push({i+1, j});
          q1.push({i, j-1});
          q1.push({i, j+1});
        }           
      }
    }
    int step = 0;
    while(!q1.empty()){
      step++;
      queue<pair<int, int>>q2;
      while(!q1.empty()){
        auto [x, y] = q1.front();
        q1.pop();
        if(x>=0 and x<r and y>=0 and y<c and g[x][y] == 0){
          g[x][y]=step;
          q2.push({x-1, y});
          q2.push({x+1, y});
          q2.push({x, y-1});
          q2.push({x, y+1});
        }
      }
      q1 = q2;
    }
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        cout<<g[i][j]<<' ';
      }
      cout<<'\n';
    }
    return (step-1)?step-1:-1;
  }
};