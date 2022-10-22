class Solution {
public:
  bool check(unordered_map<char, int>& cnt1, unordered_map<char, int>& cnt2){
    for(auto[ch, cnt]:cnt1)
      if(cnt2[ch] < cnt)
        return false;
    return true;
  }
  string minWindow(string s, string t) {
    unordered_map<char, int>cnt1, cnt2;
    int l = 0, r = 0;
    int len = INT_MAX;
    string ret = "";
    for(char ch:t)
      cnt1[ch]++;
    while(l < s.length() && r < s.length()){
      cnt2[s[r]]++;
      while(l <= r && check(cnt1, cnt2)){
        if(r-l+1 < len){
          len = r-l+1; 
          ret = s.substr(l, len);
        }
        cnt2[s[l++]]--;
      }
      r++;
    }
    if(len == INT_MAX)
      return "";
    return ret;
  }
};