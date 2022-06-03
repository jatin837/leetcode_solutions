class Solution {
public:
    pair<char, char> add_digit(char a, char b, char c){
      string res = to_string(a-'0' + b-'0' + c-'0');
      if(res.length() == 2)
        return {res[1], '1'};
      return {res[0], '0'};
    }
    string add(string num1, string num2){
      pair<char, char> out;
      if(num1.length() < num2.length()){
        while(num1.length() != num2.length()){
          num1 = '0' + num1;
        }
      }
      if(num2.length() < num1.length()){
        while(num1.length() != num2.length()){
          num2 = '0' + num2;
        }
      }
      string res="";
      out.first = '0';
      out.second = '0';
      for(int i=num1.length()-1; i>=0; i--){
        out = add_digit(num1[i], num2[i], out.second); 
        res = out.first + res;
      }
      if(out.second == '1')
        res = '1'+res;
      return res;
    }
    
    pair<char, char> multiply_digit(char a, char b, char c){
      string res = to_string(
        (a - '0')*(b - '0') + (c - '0'));
      if(res.length() == 2)
        return {res[1], res[0]};
      return {res[0], '0'};
    }
    string multiply(string num1, string num2) {
      if (num1 == "0" or num2 == "0")
        return "0";
      if(num1.length() < num2.length()){
        swap(num1, num2);
      }
      vector<string>tmp;
      for(int i=num2.length()-1; i>=0; i--){
        string res = "";
        pair<char, char> out = {'0', '0'};
        for(int j=num1.length()-1; j>=0; j--){
          out = multiply_digit(num1[j], num2[i], out.second);
          res = out.first + res;
        }
        if(out.second != '0')
          res = out.second + res;
        tmp.push_back(res);
      }
//      reverse(begin(tmp), end(tmp));
      
      string ans = tmp[0];
      for(int i=1; i<tmp.size(); i++){
        int j=0;
        while(j++<i)
          tmp[i] += '0';
        ans = add(ans, tmp[i]);
      }
      for(auto t:tmp)
        cout<<t<<' ';

      return ans;
    }
};