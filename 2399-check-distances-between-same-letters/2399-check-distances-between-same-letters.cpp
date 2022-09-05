class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
      for(int i=0; i<s.length(); i++){
        int nidx = i+d[s[i]-'a']+1;
        int pidx = i-d[s[i]-'a']-1;
        if((nidx < s.length() && s[nidx] == s[i]) || (pidx >= 0 && s[pidx] == s[i]))
          continue;
        return false;
      }
      return true;
    }
};