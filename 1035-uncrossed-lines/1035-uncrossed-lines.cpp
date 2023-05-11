class Solution {
public:
  int memo[501][501];
  int f(int i, int j, vector<int>&nums1, vector<int>&nums2){
    if(i == nums1.size() or j == nums2.size())
      return 0;
    if(memo[i][j] != -1)
      return memo[i][j];
    if(nums1[i] == nums2[j])
      memo[i][j] = 1 + f(i+1, j+1, nums1, nums2);
    else
      memo[i][j] = max(f(i+1, j, nums1, nums2), f(i, j+1, nums1, nums2));
    return memo[i][j];
  }
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    memset(memo, -1, sizeof(memo));
    return f(0, 0, nums1, nums2);
  }
};