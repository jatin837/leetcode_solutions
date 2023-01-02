class Solution {
public:
    string getHint(string A, string B) {
      int bulls = 0;
      int cows = 0;
      int fqA[10] = {0};
      int fqB[10] = {0};
      for(int i=0; i<A.size(); i++){
        if(A[i] == B[i]){
          bulls++;
        }else{
          fqA[A[i]-'0']++;
          fqB[B[i]-'0']++;
        }
      }
      for(int i=0; i<10; i++)
        cows += min(fqA[i], fqB[i]);
      string ret = to_string(bulls) + "A" + to_string(cows) + "B";
      return ret;
    }
};