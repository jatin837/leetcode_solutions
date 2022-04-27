class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int s =0, N = arr.size(), e = N-1;
    while(s <= e){
      int m = (s+e)>>1;
      if(arr[m]-m-1 < k)
        s= m+1;
      else
        e= m-1;
    }
    return k+s;
  }
};