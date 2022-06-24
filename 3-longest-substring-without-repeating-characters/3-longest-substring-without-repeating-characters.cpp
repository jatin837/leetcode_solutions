class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.length() == 0)
        return 0;
      map<char, int>idx;
      int l = 0;
      idx[s[0]] = 1;
      int ans = 1;
      for(int r = 1; r<s.length(); r++){
        if(idx[s[r]]-1 >= l)
          l = idx[s[r]];
        ans = max(ans, r-l+1);
        idx[s[r]] = r+1;
      } 
      return ans;
    }
};