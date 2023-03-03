class Solution {
public:
    int strStr(string haystack, string needle) {
      int ans = -1;
      int hl = haystack.length();
      int nl = needle.length();
      for(int i=0; i<hl-nl+1; i++){
        if(haystack.substr(i, nl) == needle)
          return i;
      }
      return -1;
    }
};