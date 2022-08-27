class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int>sumCnt;
      sumCnt[0] = 1;
      int sum = 0;
      int cnt = 0;
      for(int n:nums){
        sum += n;
        cnt += sumCnt[sum-k];
        sumCnt[sum]++;
      }
      return cnt;
    }
};