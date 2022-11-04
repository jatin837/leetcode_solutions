class Solution {
public:
    bool vowel(char ch){
      if(isalpha(ch))
        ch = tolower(ch);
      return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'; 
    }
    string reverseVowels(string s) {
      int b = 0;
      int e = s.length()-1;
      while(b<e){
        if(vowel(s[b]) and vowel(s[e])){
          swap(s[b], s[e]);
          b++;
          e--;
        }else if(vowel(s[b])){
          e--;
        }else if(vowel(s[e])){
          b++;
        }else{
          b++;
          e--;
        }
      }
      return s;
    }
};