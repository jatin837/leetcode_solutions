class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int>preCount;
      preCount[0] = 1;
      int sum = 0;
      int cnt = 0;
      for(int n:nums){
        sum += n;
        cnt += preCount[sum-k];
        preCount[sum]++;
      }
      return cnt;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int rl = matrix.size();
      int cl = matrix[0].size();
      vector<int>compressedArr(rl);
      int cnt = 0;
      for(int i=0; i<rl; i++)
        for(int j=1; j<cl; j++)
          matrix[i][j] += matrix[i][j-1];
      for(int i=0; i<cl; i++){
        for(int j=0; j<=i; j++){
          for(int k=0; k<rl; k++){
            compressedArr[k] = matrix[k][i];
            if(j != 0)
              compressedArr[k] -= matrix[k][j-1];
          }
          cnt += subarraySum(compressedArr, target);
        }
      }
      return cnt;
    }
};