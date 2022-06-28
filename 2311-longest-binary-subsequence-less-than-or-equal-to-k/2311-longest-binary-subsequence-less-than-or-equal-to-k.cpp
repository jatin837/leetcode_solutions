class Solution {
public:
    int longestSubsequence(string s, int k) {
      int zero_cnt = count(s.begin(), s.end(), '0');
      int one_cnt = 0;
      int pow = 1;
      int val = 0;
      for(int i=s.length()-1; i>=0 and pow + val <= k; i--, pow <<= 1){
        if(s[i] == '1'){
          one_cnt++;
          val += pow;
        }
      }
      return one_cnt + zero_cnt;
    }
};