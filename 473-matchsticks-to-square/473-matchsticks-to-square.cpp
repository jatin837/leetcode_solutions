class Solution {
public:
    bool dfs(vector<int> &matchsticks, int idx, int sideLen, vector<int>& sq){
      if(idx == matchsticks.size())
        return sq[0] == sq[1] and sq[1] == sq[2] and sq[3] == sq[2];
      int currMatchStick = matchsticks[idx];
      for(int i=0; i<4; i++){
        if(currMatchStick + sq[i] <= sideLen){
          sq[i]+=currMatchStick;
          if(dfs(matchsticks, idx+1, sideLen, sq))
            return true;
          sq[i]-=currMatchStick;
        }
      }
      return false;
    }
    bool makesquare(vector<int>& matchsticks) {
      int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
      if(sum%4!=0)
        return false;
      int sideLen = sum>>2;
      vector<int>sq(4, 0);
      sort(begin(matchsticks), end(matchsticks), [](int &l, int &r){ return l>r;});
      return dfs(matchsticks, 0, sideLen, sq);
    }
};

