class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int flipped = 0;
    int notflipped = 0;
    s += '1';
    for(int i=s.length()-2; i>=0; i--){
      int nflipped = 0;
      int nnotflipped = 0;
      if(s[i] == '0' && s[i+1] == '0'){
        nflipped = 1 + flipped;
        nnotflipped = min(flipped, notflipped);
      }
      else if(s[i] == '0' && s[i+1] == '1'){
        nflipped = 1 + notflipped;
        nnotflipped = min(flipped, notflipped);
      }
      else if(s[i] == '1' && s[i+1] == '0'){
        nflipped = 1+min(flipped, notflipped);
        nnotflipped = flipped;
      }
      else if(s[i] == '1' && s[i+1] == '1'){
        nflipped = 1+min(notflipped, flipped);
        nnotflipped = notflipped;
      }
      flipped = nflipped;
      notflipped = nnotflipped;
    }
    return min(flipped, notflipped);
  }
};