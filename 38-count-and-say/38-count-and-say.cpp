class Solution {
public:
    string countAndSay(int n) {
      if(n==0)
        return "";
      if(n==1)
        return "1";
      
      string ans = "";
      string res = countAndSay(n-1);
      for(int i=0; i<res.length(); i++){
        int cnt = 1;
        while(i+1<res.length() and res[i] == res[i+1]){
          cnt++;
          i++;
        }
        ans += to_string(cnt) + res[i]; 
      }
      return ans;
    }
};