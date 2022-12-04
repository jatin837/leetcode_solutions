class Solution {
public:
    void backtrack(int index, int sum, int size, vector<int>&nums, vector<vector<int>>&s){
        if(index == nums.size()){
            s[size].push_back(sum);
            return;
        }
        backtrack(index+1, sum, size, nums, s);
        backtrack(index+1, sum + nums[index], size+1, nums, s);
    }
    int minimumDifference(vector<int>& nums) {
        vector<vector<int>>s1(nums.size()/2+1);
        vector<vector<int>>s2(nums.size()/2+1);
        int s = accumulate(nums.begin(), nums.end(), 0);
        int ret = INT_MAX;
        vector<int>left(nums.begin(), nums.begin()+nums.size()/2);
        vector<int>right(nums.begin()+nums.size()/2, nums.end());
        backtrack(0, 0, 0, left, s1);
        backtrack(0, 0, 0, right, s2);
        for(int i=0; i<s2.size(); i++)
            sort(s2[i].begin(), s2[i].end());
        for(int i=0; i<s1.size(); i++){
            vector<int>a1 = s1[i];
            vector<int>a2 = s2[nums.size()/2-i];
            for(int n:a1){
                int x = s/2-n;
                auto itr = lower_bound(a2.begin(), a2.end(), x);
                if(itr != a2.end())
                    ret = min(ret, abs(2*(*itr + n) - s));
                if(itr != a2.begin())
                    ret = min(ret, abs(2*(*prev(itr) + n) - s));
            }
        }
        return ret;
    }
    
    
};