class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
      int MOD = 1e9+7;
      int N = arr.size();
      vector<long long>dp(N, 1);
      sort(arr.begin(), arr.end());
      unordered_map<long long, long long> indx;
      for(long long i=0; i<N; i++)
        indx[arr[i]] = i+1;
      for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
          if(arr[i]%arr[j] == 0 && indx[arr[i]/arr[j]]){
            int lidx = j;
            int ridx = indx[arr[i]/arr[j]];
            dp[i] = (dp[i] + dp[j] * dp[ridx-1])%MOD;
          }
        }
      }
      long long ans = 0;
      for(long long n:dp) ans = (n + ans)%MOD;
      return ans%MOD;
    }
};