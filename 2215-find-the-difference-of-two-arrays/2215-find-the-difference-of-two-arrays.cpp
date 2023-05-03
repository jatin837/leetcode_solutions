class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int, int> f1, f2;;        
      unordered_set<int> a1;
      unordered_set<int> a2;
      for(auto x:nums1)
        f1[x] = 1;
      for(auto x:nums2)
        f2[x] = 1;
        
      for(auto x:nums1)
        if (f2[x] == 0)
          a1.insert(x);
      
      for(auto x:nums2)
        if (f1[x] == 0)
          a2.insert(x);
      
      vector<vector<int>> ans = {vector(a1.begin(), a1.end()), vector(a2.begin(), a2.end())};
      return ans;
    }
};