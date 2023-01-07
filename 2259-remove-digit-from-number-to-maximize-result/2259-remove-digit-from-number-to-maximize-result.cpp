class Solution {
public:
    string removeDigit(string num, char digit) {
      // The algorithm
      // remove the first digit where adjecent digit on the right is strictly greater
      // else if we are unable to find any such digit, replace the last digit
      int p = 0;
      int i = 0;
      while(i+1 < num.length()){
        if((num[i] == digit) && (num[i+1] > digit))
          return num.substr(0, i) + num.substr(i+1);
        if(num[i] == digit)
          p = i;
        i++;
      }
      if(num.back() == digit)
        return num.substr(0, num.size()-1);
      return num.substr(0, p) + num.substr(p+1);
    }
};