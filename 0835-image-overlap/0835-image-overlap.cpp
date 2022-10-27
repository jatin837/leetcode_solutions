class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
      int ans = 0;
      int N = img1.size();
      for(int i=-1*N; i<N; i++){
        for(int j=-1*N; j<N; j++){
          int cnt = 0;
          for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
              if(r-i < 0 || c-j < 0 || r-i >= N || c-j >= N)
                continue;
              cnt += img1[r-i][c-j]*img2[r][c];
            }
          }
          ans = max(cnt, ans);
        }
      }
      return ans;
    }
};