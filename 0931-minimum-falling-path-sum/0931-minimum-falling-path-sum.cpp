class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n = matrix.size();
      vector<int> next;
      vector<int> prev = vector(matrix[0].begin(), matrix[0].end());
      for(int i=1; i<n; i++){
        next = vector(matrix[i].begin(), matrix[i].end()); 
        vector<int>tmp (n, 1e8);
        for(int j=0; j<n; j++)
          for(int k=-1; k<2; k++)
            if (j+k >=0 and j+k<n)
              tmp[j] = min(tmp[j], prev[j+k] + next[j]);
        prev = vector(tmp.begin(), tmp.end());
      }
     return *min_element(prev.begin(), prev.end()); 
    }
};