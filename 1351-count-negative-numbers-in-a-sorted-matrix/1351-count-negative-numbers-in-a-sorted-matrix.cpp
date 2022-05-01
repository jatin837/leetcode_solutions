class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int ans = 0;
      int m = grid.size();
      int n = grid[0].size();
      for(auto g:grid){
        reverse(g.begin(), g.end());
        ans += (lower_bound(g.begin(), g.end(), 0)-g.begin());
      }
      return ans;
    }
};