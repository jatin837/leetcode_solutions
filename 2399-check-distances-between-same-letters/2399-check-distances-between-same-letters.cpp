class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
      unordered_set<int>visited;
      for(int i=0; i<s.length(); i++){
        if(visited.count(i))
          continue;
        char ch = s[i];
        int nidx = i + d[ch-'a']+1;
        if(nidx >= s.length() || s[nidx] != ch)
          return false;
        visited.insert(nidx);
      }
      return true;
    }
};