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
        if(r == 0){
          round+=q;
          continue;
        }
        round += (q-1)+2;
      }
      return round;
    }
};