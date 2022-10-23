class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int s1 = accumulate(nums.begin(), nums.end(), 0);
    int s2 = (nums.size())*(nums.size()+1)/2;
    unordered_set<int>st(nums.begin(), nums.end());
    for(int i=1; i<=nums.size(); i++)
      if(st.count(i) == 0)
        return {i+s1-s2, i};
    return {};
  }
};