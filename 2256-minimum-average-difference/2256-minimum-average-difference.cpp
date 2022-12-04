class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long tot = accumulate(nums.begin(), nums.end(), (long long)0);
        cout<<tot;
        int N = nums.size();
        long long a = 0;
        int ret = 0;
        double diff = INT_MAX;
        for(int i=0; i<nums.size()-1; i++){
            a += (long long)nums[i];
            long long b = tot - a;
            if(abs((double)(a/(i+1)) - (double)(b/(N-i-1))) < diff){
                ret = i;
                diff = abs((double)(a/(i+1)) - (double)(b/(N-i-1)));
            }
        }
        if((double)((a + nums.back())/nums.size()) < diff)
            return nums.size()-1;
        return ret;
    }
};