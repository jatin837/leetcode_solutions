#include <bits/stdc++.h>
class Solution {
public:
    static bool cmp(string &s1, string &s2) {
      return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
      vector<string> str_nums;
      for(int i=0; i<nums.size(); i++)
        str_nums.push_back(to_string(nums[i])); 
      sort(str_nums.begin(), str_nums.end(), this->cmp);
      string s;
      for(auto si:str_nums)
        s += si;
      if(s[0] == '0')
        return "0";
      return s;
    }
};