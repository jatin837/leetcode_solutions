#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
      auto it = lower_bound(nums.begin(), nums.end(), target);
      if(nums.size() == 1)
        if(nums[0] == target)
          return 0;
        else
          return -1;
      if (target != *it)
        return -1;
      return it - nums.begin();
    }
  
};