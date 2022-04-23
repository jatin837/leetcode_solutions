#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
      sort(arr2.begin(), arr2.end());
      int N = arr2.size();
      int ans = 0;
      for(auto n:arr1){
        int idx = upper_bound(arr2.begin(), arr2.end(), n) - arr2.begin();
        if(idx > 0 and idx < N)
          if(abs(n - arr2[idx-1]) > d and abs(n - arr2[idx]) > d)
            ans++;
        if(idx == 0 and abs(n-arr2[idx]) > d)
          ans++;
        if(idx == N and abs(n-arr2[idx-1]) > d)
          ans++;
      }
      return ans;
    }
};