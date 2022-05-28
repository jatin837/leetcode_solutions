//class Solution {
//public:
//    string toHex(int num) {
//      string ans = "";
//      while(num){
//        int d = num%16; 
//        if(d>9)
//          ans = char('a'+(d-10))+ ans;
//        else
//          ans = to_string(d) + ans;
//        num/=16;
//      }
//      return ans;
//    }
//};

const string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            result = HEX[(num & 0xf)] + result;
            num >>= 4;
        }
        return result;
    }
};