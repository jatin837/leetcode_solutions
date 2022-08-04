//class Solution {
//public:
//    int kthSmallest(vector<vector<int>>&M , int k) {
//      int b = M[0][0], e = M.back().back();
//      int ans = -1;
//      while(b<e){
//        long long m = (b+e)>>1;
//        int smlCnt = 0;
//        for(int i=0; i<M.size(); i++)
//          smlCnt += upper_bound(M[i].begin(), M[i].end(), m)-M[i].begin();
//          if (smlCnt >= k)
//            ans=m, e=m-1;
//          else
//            b=m+1;
//      }
//      return ans;
//    }
//};

class Solution {
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
          int cnt = 0;
          for(int i=0; i<matrix.size(); i++){
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
          }
            if (cnt >= k) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }
};