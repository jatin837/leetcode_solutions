class Solution {
public:
    int binarySearch(vector<int> &arr, int s, int e, int target){
      int ans=-1;
      while(s<=e){
        int m = (s+e)>>1;
        if(target <= arr[m]){
          ans = m;
          s=m+1;
        }else{
          e=m-1;
        }
      }
      return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int max_i = 0;
        for(int i=0; i<n; i++){
            int res = binarySearch(nums2, i, m-1, nums1[i]);
            cout<<res<<'\n';
            if (res!=-1){
                int diff = res-i;
                max_i = max(diff, max_i);
            }
        }
        return max_i;
    }
};