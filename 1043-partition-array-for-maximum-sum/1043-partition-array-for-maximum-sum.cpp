class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int dp[501] = {0};
      for(int i=1; i<arr.size()+1; i++){
        int mx = 0;
        for(int j=1; j<=k && i-j>=0; j++){
          mx = max(mx, arr[i-j]);
          dp[i] = max(dp[i], dp[i-j] + mx*j);
        }
      }
      return dp[arr.size()];
    }
};