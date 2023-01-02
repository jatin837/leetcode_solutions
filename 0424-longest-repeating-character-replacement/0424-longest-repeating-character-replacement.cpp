class Solution {
public:
    int myMax(int fq[]){
      int ret = 0;
      for(int i=0; i<26; i++)
        ret = max(ret, fq[i]);
      return ret;
    }
    int characterReplacement(string s, int k) {
      int fq[26] = {0};
      int ret = 0;
      int left = 0;
      int right = 0;
      fq[s[right]-'A']++;
      while(left < s.length() && right < s.length()){
        int len = right - left + 1;
        int ops = len - myMax(fq);
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