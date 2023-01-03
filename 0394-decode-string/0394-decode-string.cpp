class Solution {
  string f(string &s, int beg, int end){
    string ret = "";
    int len = end-beg+1;
    int currNum = 0;
    int i=beg;
    while(i<=end){
      if(isdigit(s[i])){
        currNum = 10*currNum + (s[i]-'0');
        i++;
        continue;
      }
      if(s[i] == '['){
        int j = i+1;
        i++;
        int cnt = 1;
        while(i<=end and cnt){
          if(s[i]== '[')
            cnt++;
          else if(s[i] == ']')
            cnt--;
          i++;
        }
        string a = f(s, j, i-2);
        string b = f(s, i, end);
        while(currNum--) ret += a;
        return ret+b;
      }
      ret += s[i];
      i++;
    }
    return ret;
  }
public:
    string decodeString(string s) {
      return f(s, 0, s.length()-1);
    }
};