class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int m = upper_bound(begin(arr), end(arr), x)-begin(arr)-1;
      int b = max(0, m+1-k);
      int e = b + k - 1;
      vector<int>ret;
      while(e+1 < arr.size() && abs(arr[b]-x) > abs(arr[e+1] - x))
        b++,e++;
      for(int i=b; i<=e; i++)
        ret.push_back(arr[i]);
      return ret;
    }
};