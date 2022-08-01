class Solution {
public:
    int nearestExit(vector<vector<char>>& M, vector<int>& E) {
      vector<pair<int, int>> dd = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
      int m = M.size();
      int n = M[0].size();
      queue<array<int, 3>>q;
      q.push({E[0], E[1], 0});
      while(!q.empty()){
        auto [x, y, dist] = q.front();
        q.pop();
        if(x<0 || y<0 || x>=m || y>=n || M[x][y] == '+')
          continue;
        M[x][y] = '+';
        if((x == 0 || y == 0 || x == m-1 || y == n-1) && !(x == E[0] && y == E[1]))
          return dist;
        for(auto [dx, dy]:dd)
          q.push({x+dx, y+dy, dist+1});
      }
      return -1;
    }
};