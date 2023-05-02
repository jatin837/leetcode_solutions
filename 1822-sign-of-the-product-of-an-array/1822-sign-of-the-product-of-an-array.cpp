class Solution {
public:
    int arraySign(vector<int>& nums) {
      int ret = 1;
      for(auto n:nums)
        if(n == 0)
          return 0;
        else if(n < 0)
          ret *= -1;
        else
          ret *= 1;
      return ret;
    }
};