class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        long long dp[100001];
        long long mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[zero] += 1;
        dp[one] += 1;
        long long ret = 0;
        for(int i=min(zero, one); i<=high; i++){
            if(i-zero >= 0)
                dp[i] = (dp[i] + dp[i-zero])%mod;
            if(i-one >= 0)
                dp[i] = (dp[i] + dp[i-one])%mod;
            if(i >= low and i <= high)
                ret = (dp[i] + ret)%mod;
        }
        return ret;
    }
};