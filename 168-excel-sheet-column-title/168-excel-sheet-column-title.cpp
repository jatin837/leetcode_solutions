class Solution {
public:
    string convertToTitle(int columnNumber) {
      
      string ans="";
      while(columnNumber){
        if(columnNumber<=26){
          ans = char('A' + (columnNumber-1)) + ans;
        }
        else{
          char digit = 'A' + (columnNumber-1)%26;
          ans = digit + ans;
        }
        if(columnNumber%26 == 0)
          columnNumber--;
        columnNumber/=26;
      }
      
      return ans;
    }
};