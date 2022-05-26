class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      map<int, int>fq;
      for(auto num:nums){
        if(fq[num]>=1)
          return true;
        fq[num]++;
      } 
      return false;
    }
};