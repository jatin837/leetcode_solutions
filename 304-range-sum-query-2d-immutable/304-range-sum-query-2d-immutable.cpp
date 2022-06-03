class NumMatrix {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
      this->matrix = matrix;
        int r=this->matrix.size();
      int c=this->matrix[0].size();
      vector<vector<int>> prefix(r, vector<int>(c, 0));
      
      for(int i=0; i<r; i++)
        prefix[i][0] = matrix[i][0];
      for(int i=0; i<r; i++)
        for(int j=1; j<c; j++)
          prefix[i][j] += prefix[i][j-1] + matrix[i][j];

      for(int i=1; i<r; i++)
        for(int j=0; j<c; j++)
          prefix[i][j] += prefix[i-1][j];

        
//////for(auto r:prefix){
//////  for(auto c:r){
//////    cout<<c<<' ';
//////  }
//////  cout<<'\n';
//////}
//////cout<<'\n';
      this->prefix = prefix;

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    
      int ri = row1-1;
      int ci = col1-1;
      int ans = prefix[row2][col2];
      if (ri >= 0)
        ans -= prefix[ri][col2];
      if (ci >= 0)
        ans -= prefix[row2][ci];
      if (ri >= 0 and ci >= 0)
        ans += prefix[ri][ci];
      return ans; 
      
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */