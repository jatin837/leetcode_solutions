class Solution {
public:
   array<int, 13> values = {
    1000,
    900,
    500,
    400,
    100,
    90,
    50,
    40,
    10,
    9,
    5,
    4,
    1
  };
  array<string, 13> roman_literals = {
    "M",
    "CM",
    "D",
    "CD",
    "C",
    "XC",
    "L",
    "XL",
    "X",
    "IX",
    "V",
    "IV",
    "I"
  };     
  
  string intToRoman(int num) {
    string result ="";
    for(int i=0; i<13; i++){
      if(num >= values[i]){
        do{
          num -= values[i];
          result += roman_literals[i];
        } while(num >= values[i]);
      }
    }
    return result;
  }
};