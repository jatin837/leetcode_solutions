class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      set<int>ans;
      sort(nums2.begin(), nums2.end());
      for(int i=0; i<nums1.size(); i++){
        auto idx = lower_bound(begin(nums2), end(nums2), nums1[i]) - nums2.begin();;
        if(idx >= nums2.size() or nums2[idx] != nums1[i])
          continue;
        ans.insert(nums1[i]);
      }
      return vector(begin(ans), end(ans));
    }
};