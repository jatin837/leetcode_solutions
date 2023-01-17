class Solution {
public:
  int flipped[100001];
  int notflipped[100001];
  int minFlipsMonoIncr(string s) {
    int flipped = 0;
    int notflipped = 0;
    s += '1';
    for(int i=s.length()-2; i>=0; i--){
      int nflipped = 0;
      int nnotflipped = 0;
      if(s[i] == '0'){
        (s[i+1] == '0')?nflipped = 1+flipped:nflipped = 1 + notflipped;
        nnotflipped = min(flipped, notflipped);
      }
      else {
        nflipped = 1+min(flipped, notflipped);
        (s[i+1] == '0')?nnotflipped = flipped:nnotflipped = notflipped;
      }
      flipped = nflipped;
      notflipped = nnotflipped;
    }
    return min(flipped, notflipped);
  }
};