class Solution {
public:
    int characterReplacement(string s, int k) {
      int fq[26] = {0};
      int ret = 0;
      int left = 0;
      int right = 0;
      int maxf = 0;
      fq[s[right]-'A']++;
      while(left < s.length() && right < s.length()){
        int len = right - left + 1;
        maxf = max(maxf, fq[s[right]-'A']);
        int ops = len - maxf;
        if(ops <= k){
          ret = max(len, ret);
          right++;
          if(right < s.length())
            fq[s[right]-'A']++;
          continue;
        }
        fq[s[left]-'A']--;
        left++;
      }
      return ret;
    }
};