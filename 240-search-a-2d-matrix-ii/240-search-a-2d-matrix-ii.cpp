class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
      int r=0, c=m[0].size()-1;
      while(r<m.size() and c >= 0){
        if(m[r][c] == t)
          return true;
        else if(m[r][c] > t)
          c--;
        else if(m[r][c] < t)
          r++;
      }
      return false;
    }
};