class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int rl = matrix.size();
      int cl = matrix[0].size();
      int cnt = 0;
      for(int i=0; i<rl; i++)
        for(int j=1; j<cl; j++)
          matrix[i][j] += matrix[i][j-1];
      for(int i=0; i<cl; i++){
        for(int j=0; j<=i; j++){
          unordered_map<int, int> preCnt;
          preCnt[0] = 1;
          int sum = 0;
          for(int k=0; k<rl; k++){
            sum += matrix[k][i];
            if(j != 0)
              sum -= matrix[k][j-1];
            cnt += preCnt[sum - target];
            preCnt[sum]++;
          }
        }
      }
      return cnt;
    }
};