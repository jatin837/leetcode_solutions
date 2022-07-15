class Solution {
public:
    void setZero(int r, int c, vector<vector<int>>&matrix){
      for(int i=0; i<matrix.size(); i++)
        matrix[i][c] = 0;
      for(int i=0; i<matrix[0].size(); i++)
        matrix[r][i] = 0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
      vector<bool>x(matrix.size(), false);
      vector<bool>y(matrix[0].size(), false);
      for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
          if(matrix[i][j])
            continue;
          x[i] = true;
          y[j] = true;
        }
      }
      for(int i=0; i<x.size(); i++)
        if(x[i])
          for(int k=0; k<y.size(); k++)
            matrix[i][k] = 0;
      for(int i=0; i<y.size(); i++)
        if(y[i])
          for(int k=0; k<x.size(); k++)
            matrix[k][i] = 0;
    }
};