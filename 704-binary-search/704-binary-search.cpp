#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
      auto it = lower_bound(nums.begin(), nums.end(), target);
      if(it == nums.end()){
        return -1;
      }
      if (target != *it){
        return -1;
      }
      return it - nums.begin();
    }
  
};