class Solution {
public:
    int minimumDeletions(string s) {
      int len = s.length();
      int bcnt = 0;
      int dp1=0;int dp2=0;
      for(int i=0; i<len; i++){
        if(s[i] == 'a'){
          dp2=min(dp1+1, bcnt);
        }else{
          bcnt++;
          dp2=dp1;
        }
        dp1=dp2;
      }
      return dp2;
    }
};