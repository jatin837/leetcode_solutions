class Solution {
public:
  int flipped[100001];
  int notflipped[100001];
  int minFlipsMonoIncr(string s) {
    flipped[s.length()] = 0;
    notflipped[s.length()] = 0;
    s += '1';
    for(int i=s.length()-2; i>=0; i--){
      if(s[i] == '0' && s[i+1] == '0'){
        flipped[i] = 1 + flipped[i+1];
        notflipped[i] = min(flipped[i+1], notflipped[i+1]);
      }
      if(s[i] == '0' && s[i+1] == '1'){
        flipped[i] = 1 + notflipped[i+1];
        notflipped[i] = min(flipped[i+1], notflipped[i+1]);
      }
      if(s[i] == '1' && s[i+1] == '0'){
        flipped[i] = 1+min(flipped[i+1], notflipped[i+1]);
        notflipped[i] = flipped[i+1];
      }
      if(s[i] == '1' && s[i+1] == '1'){
        flipped[i] = 1+min(notflipped[i+1], flipped[i+1]);
        notflipped[i] = notflipped[i+1];
      }
    }
    return min(flipped[0], notflipped[0]);
  }
};