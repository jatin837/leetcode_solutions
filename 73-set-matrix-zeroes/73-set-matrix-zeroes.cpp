class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      unordered_set<int>x, y;
      for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
          if(!matrix[i][j])  { x.insert(i);y.insert(j); }
      
      for(int i:x)
        for(int j=0; j<matrix[0].size(); j++)
          matrix[i][j] = 0;
        
      for(int i:y)
        for(int j=0; j<matrix.size(); j++)
          matrix[j][i] = 0;
    }
};