class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
      vector<long long>preSum(chalk.size(), 0);
      preSum[0] = chalk[0];
      for(int i=1; i<chalk.size(); i++)
        preSum[i] = chalk[i] + preSum[i-1];
      k %= preSum.back();
      int idx = upper_bound(begin(preSum), end(preSum), k)-begin(preSum);
      return idx;
    }
};