class Solution {
public:
    int findCWL(string&s, string&t, int i, int j, int d){
      int len = 0;
      while(i<s.length() and i >= 0 and j <t.length() and j >= 0){
        if(s[i] != t[j])
          return len;
        i+=d;
        j+=d;
        len++;
      }
      return len;
    }
    int countSubstrings(string s, string t) {
      int ans = 0;
      int i=0;
      int j=0;
      for(i=0; i<s.length(); i++){
        for(j=0; j<t.length(); j++){
          if(s[i] != t[j]){
            int l = findCWL(s, t, i-1, j-1, -1);
            int r = findCWL(s, t, i+1, j+1, 1);
            ans += (l+1)*(r+1);
          }
        }
      }
      return ans;
    }
};