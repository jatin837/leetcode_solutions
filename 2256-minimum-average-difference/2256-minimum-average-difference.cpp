class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long>preSum(nums.size(), 0);
        preSum[0] = nums[0];
        int ret = 0;
        double diff = INT_MAX;
        for(int i=1; i<nums.size(); i++)
            preSum[i] = preSum[i-1] + nums[i];
        for(int i=1; i<nums.size();i++){
            double a = preSum[i-1]/i;
            double b = (preSum.back()-preSum[i-1])/(nums.size()-i);
            if(abs(a-b) < diff){
                diff = abs(a-b);
                ret = i-1;
            }
        }
        if(preSum.back()/nums.size() < diff)
            return nums.size()-1;
        return ret;
    }
};