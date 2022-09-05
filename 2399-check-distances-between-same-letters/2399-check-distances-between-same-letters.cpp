class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
      for(int i=0; i<s.length(); i++){
        char ch = s[i];
        int nidx = i+d[ch-'a']+1;
        int pidx = i-d[ch-'a']-1;
        if((nidx < s.length() && s[nidx] == ch) || (pidx >= 0 && s[pidx] == ch))
          continue;
        return false;
      }
      return true;
    }
};