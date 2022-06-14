class Solution {
public:
    int thirdMax(vector<int>& nums) {
      set<int> max3;
      for (int num : nums) {
        max3.insert(num);
        if (max3.size() > 3)
          max3.erase(max3.begin());
      }
      return max3.size() == 3 ? *max3.begin() : *max3.rbegin();
    }
};