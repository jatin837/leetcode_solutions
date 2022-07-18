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
};