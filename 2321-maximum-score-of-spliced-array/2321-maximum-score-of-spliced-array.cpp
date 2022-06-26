class Solution {
public:
    int kadane(vector<int>& arr){
      int best = 0;
      int sum = 0;
      for(int i=0; i<arr.size(); i++){
        sum = max(arr[i], arr[i]+sum);
        best = max(best, sum);
      }
      return best;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
      vector<int>diff(nums1.size());
      int s1 = 0, s2 = 0;
      for(int i=0; i<nums1.size(); i++){
        diff[i] = nums1[i] - nums2[i];
        s1 += nums1[i];
        s2 += nums2[i];
      }
      int k1 = kadane(diff);
      for(int i=0; i<nums1.size(); i++){
        diff[i] = nums2[i] - nums1[i];
      }
      int k2 = kadane(diff);
      int ans = max(s1, s2);
      ans = max(s1+k2, ans);
      ans = max(s2+k1, ans);
      return ans;
    }
};