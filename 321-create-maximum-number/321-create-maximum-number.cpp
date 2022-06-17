//class Solution {
//public:
//    vector<int>maxArr(vector<int>&nums, int len){}
//    bool greater(vector<int>&first, vector<int>&second){}
//    vector<int>merge(vector<int>&nums1, vector<int>&nums2){}
//    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){}
//};

class Solution {
  
public:
vector<int> maxNumber(vector<int> nums1, vector<int> nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int>ans(k);
    for (int i = max(0, k - m); i <= k && i <= n; ++i) {
        vector<int> candidate = merge(maxArray(nums1, i), maxArray(nums2, k - i), k);
        if (greater(candidate, 0, ans, 0)) ans = candidate;
    }
    return ans;
}
vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
    vector<int> ans(k);
    for (int i = 0, j = 0, r = 0; r < k; ++r)
        ans[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    return ans;
}
bool greater(vector<int> nums1, int i, vector<int> nums2, int j) {
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
        i++;
        j++;
    }
    return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
}
vector<int> maxArray(vector<int> nums, int k) {
    int n = nums.size();
    vector<int> ans(k);
    for (int i = 0, j = 0; i < n; ++i) {
        while (n - i + j > k && j > 0 && ans[j - 1] < nums[i]) j--;
        if (j < k) ans[j++] = nums[i];
    }
    return ans;
}
};