class Solution {
public:
    string getHint(string A, string B) {
      int bulls = 0;
      int cows = 0;
      int fq[10] = {0};
      for(int i=0; i<A.size(); i++) fq[A[i]-'0']++;
      for(int i=0; i<A.size(); i++){
        if(A[i] == B[i]){
          bulls++;
          fq[A[i]-'0']--;
          A[i] = '-';
        }
      }
      for(int i=0; i<A.size(); i++){
        if(A[i] != '-' && fq[B[i]-'0'] > 0){
          cows++;
          fq[B[i]-'0']--;
        }
      }
      string ret = to_string(bulls) + "A" + to_string(cows) + "B";
      return ret;
    }
};