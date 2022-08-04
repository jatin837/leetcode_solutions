class Solution {
public:
    int findKthNumber(int m, int n, int k) {
      int s = 1, e = m*n;
      while(s<e){
        long long mid = (s + e)>>1;
        int smlCnt = 0;
        for(int i=1; i<=m; i++)
          smlCnt += min(n, int(mid/i)); 
        if(smlCnt < k)
          s = mid+1;
        else
          e = mid;
      }
      return s;
    }
};