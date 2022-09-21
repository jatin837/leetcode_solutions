class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      vector<int>ans;
      int sum = 0;
      for(int n:nums)
        if(n%2==0)
          sum += n;
      for(auto q:queries){
        nums[q[1]] += q[0];
        if(nums[q[1]]%2 == 0){
          if((nums[q[1]] - q[0])%2 == 0)
            sum += q[0];
          else
            sum += nums[q[1]];
        }else{
          if((nums[q[1]]-q[0])%2 == 0)
            sum -= nums[q[1]]-q[0];
        }
        ans.push_back(sum);
      }
      return ans;
    }
};