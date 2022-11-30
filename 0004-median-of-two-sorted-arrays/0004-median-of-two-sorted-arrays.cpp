class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if(m > n)
        return findMedianSortedArrays(nums2, nums1);
    int s = 0;
    int e = m-1;
    while(true){
      int ma = (s+e)>>1; // mid position in nums1 array
      int mb = (m+n)/2 - (ma + 1) - 1; // mid position in nums2 array
      int Aleft = (ma>=0)?nums1[ma]:INT_MIN;
      int Aright = (ma+1>=nums1.size())?INT_MAX:nums1[ma+1];
      int Bleft = (mb>=0)?nums2[mb]:INT_MIN;
      int Bright = (mb+1>=nums2.size())?INT_MAX:nums2[mb+1];
      if (Aleft <= Bright and Bleft <= Aright){
        if ((m+n)&1)
          return min(Aright, Bright);
        double a = max(Aleft, Bleft);
        double b = min(Aright, Bright);
        double ans = (a + b)/2;
        return ans; 
      }else if(Aleft > Bright)
        e = ma-1;
      else
        s = ma+1;
    }
  }
};