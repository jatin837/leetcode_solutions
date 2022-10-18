class Solution {
public:
    string say(string res){
      string ans = "";
      int i=0;
      while(i < res.length()){
        int cnt = 1;
        while(i+1<res.length() and res[i] == res[i+1]){
          cnt++;
          i++;
        }
        ans += to_string(cnt) + res[i]; 
        i++;
      }
      return ans;
    }
    string countAndSay(int n) {
      if(n==0)
        return "";
      if(n==1)
        return "1";
      return say(countAndSay(n-1));

    }
};