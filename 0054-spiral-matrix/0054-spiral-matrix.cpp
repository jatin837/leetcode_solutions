class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int r1 = 0;
      int c1 = 0;
      int r2 = matrix.size()-1;
      int c2 = matrix[0].size()-1;
      return solve(r1, c1, r2, c2, matrix);
    }
    vector<int>solve(int r1, int c1, int r2, int c2, vector<vector<int>>&matrix){
      if(r2-r1 == 1 and c2 - c1 == 1){
        return {matrix[r1][c1], matrix[r1][c2], matrix[r2][c2], matrix[r2][c1]};
      }
      if(r2 - r1 == 1 and c1 != c2){
        vector<int>res2;
        for(int i=c1; i<=c2; i++)
          res2.push_back(matrix[r1][i]);
        for(int i=c2; i>=c1; i--)
          res2.push_back(matrix[r2][i]);
        return res2;
      }
      if(c2 - c1 == 1 and r1 != r2){
        vector<int>res2;
        res2.push_back(matrix[r1][c1]);
        res2.push_back(matrix[r1][c2]);
        for(int i=r1+1; i<=r2-1; i++)
          res2.push_back(matrix[i][c2]);
        res2.push_back(matrix[r2][c2]);
        res2.push_back(matrix[r2][c1]);
        for(int i=r2-1; i>=r1+1; i--)
          res2.push_back(matrix[i][c1]);
        return res2;
      }
      if(r2 == r1){
        vector<int>res2;
        for(int i=c1; i<=c2; i++)
          res2.push_back(matrix[r1][i]); 
        return res2;
      }
      if(c1 == c2){
        vector<int>res2;
        for(int i=r1; i<=r2; i++)
          res2.push_back(matrix[i][c1]); 
        return res2;
      }
      vector<int>ans;
      for(int i=c1; i<=c2; i++){
        ans.push_back(matrix[r1][i]);
      }
      for(int i=r1+1; i<=r2-1; i++){
        ans.push_back(matrix[i][c2]);
      }
      for(int i=c2; i>=c1; i--){
        ans.push_back(matrix[r2][i]);
      }
      for(int i=r2-1; i>=r1+1; i--){
        ans.push_back(matrix[i][c1]);
      }
      vector<int> res = solve(r1+1, c1+1, r2-1, c2-1, matrix);
      for(auto num:res)
        ans.push_back(num);
      return ans;
    }
};