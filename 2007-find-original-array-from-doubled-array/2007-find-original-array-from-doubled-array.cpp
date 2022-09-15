class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
      if(nums.size()%2)
        return {};
      vector<int>ret;
      map<int, int>mp;
      set<int>st(nums.begin(), nums.end());
      for(int num:nums)
        mp[num]++;
      if(mp[0]%2)
        return {};
      mp[0] /= 2;
      for(int n:st){
        if(mp[n] > mp[2*n])
          return {};
        for(int i=0; i<mp[n]; i++)
          ret.push_back(n);
        mp[2*n] -= mp[n];
      }
      return ret;
    }
};