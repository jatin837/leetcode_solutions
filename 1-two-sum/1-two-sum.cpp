class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
      unordered_map<int, int> mp;
      for(int i=0; i<n.size(); i++){
        if(mp[t-n[i]])
          return {i, mp[t-n[i]]-1};
        mp[n[i]] = i+1;
      }
      return {-1, -1};
  }
};
