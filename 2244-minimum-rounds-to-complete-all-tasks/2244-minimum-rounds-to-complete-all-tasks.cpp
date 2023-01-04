class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
      unordered_map<int, int>mp;
      for(auto task:tasks)
        mp[task]++;
      int round = 0;
      for(auto [x, y]:mp){
        if (y<2)
          return -1;
        int q = y/3;
        int r = y%3;
        round += q + int(r != 0);
      }
      return round;
    }
};