class Solution {
public:
    pair<char, char> add(char d1, char d2, char c){
      string add_res = to_string(d1-'0' + d2-'0' + c-'0');
      if(add_res.length()==2)
        return {'1', add_res[1]};
      return {'0', add_res[0]};
    }
    string addStrings(string num1, string num2) {
      int len1 = num1.length();
      int len2 = num2.length();
      string ans = "";
      pair<char, char> out;
      out.first = '0';
      for(int i=0; i<max(len1, len2); i++){
        char d1;
        char d2;
        if(len1-i-1 >= 0)
          d1 = num1[len1-i-1];
        else
          d1 = '0';
        if(len2-i-1 >= 0)
          d2 = num2[len2-1-i];
        else
          d2 = '0';
        out = add(d1, d2, out.first);
        ans = out.second + ans;
      }
      if(out.first != '0')
        ans = out.first + ans;
      return ans;
    }
};