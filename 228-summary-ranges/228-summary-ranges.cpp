class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string>ans;
      int s = 0;
      int e = 0;
      int len = nums.size();
      while(s<len and e<len){
        while(e+1<len)
          if((long long)nums[e+1] - (long long)nums[e] == 1)
            e++;
          else
            break;
        if(s==e)
          ans.push_back(to_string(nums[s]));
        else
          ans.push_back(to_string(nums[s]) + "->" + to_string(nums[e]));
        s = e+1;
        e = s;
      }
      return ans;
    }
};