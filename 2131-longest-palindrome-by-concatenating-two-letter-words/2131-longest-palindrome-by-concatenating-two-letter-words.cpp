class Solution {
public:
    int longestPalindrome(vector<string>& ws) {
      unordered_map<string, int>mp;
      for(string w:ws)
        mp[w]++;
      int ret = 0;
      bool centeral = false;
      for(auto [w, cnt]:mp){
        if(w[0] > w[1]){
          string rev_w = w.substr(1, 1) + w.substr(0, 1);
          ret += 2*min(mp[w], mp[rev_w]);
        }else{
          if(w[0] == w[1]){
            if(cnt%2 == 1)
              centeral = true;
            ret += (cnt/2)*2;
          }
        }
      }
      return 2*(ret + int(centeral == true));
    }
};