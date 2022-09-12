class Solution {
public:
    int bagOfTokensScore(vector<int>& toks, int pow) {
      sort(begin(toks), end(toks));
      int sc=0;
      int b=0;
      int e=toks.size()-1;
      while(b <= e){
        if(toks[b] <= pow){
          sc++;
          pow-=toks[b++];
          continue;
        }
        if(sc > 0 && b != e){
          sc--;
          pow+=toks[e--];
          continue;
        }
        break;
      }
      return sc;
    }
};