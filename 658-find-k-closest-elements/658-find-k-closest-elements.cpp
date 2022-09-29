class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      vector<pair<int, int>>diff(arr.size());
      for(int i=0; i<arr.size(); i++)
        diff[i] = {abs(arr[i] - x), i};
      sort(diff.begin(), diff.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first)
          return a.second < b.second;
        return a.first < b.first;
      });
      vector<int>ret(k);
      for(int i=0; i<k; i++)
        ret[i] = arr[diff[i].second];
      sort(ret.begin(), ret.end());
      return ret;
    }
};