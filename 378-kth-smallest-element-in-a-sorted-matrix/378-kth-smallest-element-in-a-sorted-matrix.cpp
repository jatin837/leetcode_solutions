class Solution {
public:
    int kthSmallest(vector<vector<int>>&M , int k) {
      int b = M[0][0], e = M.back().back();
      int ans = -1;
      while(b<=e){
        long long m = (b+e)>>1;
        int smlCnt = 0;
        for(int i=0; i<M.size(); i++)
          smlCnt += upper_bound(M[i].begin(), M[i].end(), m)-M[i].begin();
        if(smlCnt >= k){
          ans = m;
          e = m-1;
        }
        else
          b = m+1;
      }
      return ans;
    }
};