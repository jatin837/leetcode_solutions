class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int b = 0;
      int e = arr.size() - 1;
      int m = (b + e)>>1;
      while(!(arr[m] > arr[m-1] and arr[m] > arr[m+1])){
        if(arr[m] > arr[m-1])
          b = m;
        else
          e = m;
        m = (b + e)>>1;
      }
      return m;
    }
};
