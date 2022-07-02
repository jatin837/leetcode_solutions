class Solution {
public:
    int maxArea(int hh, int ww, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      sort(horizontalCuts.begin(), horizontalCuts.end());
      sort(verticalCuts.begin(), verticalCuts.end());
      long long maxH=horizontalCuts[0];
      long long maxW=verticalCuts[0];
      for(int i=1; i<horizontalCuts.size(); i++){
        long long h = horizontalCuts[i] - horizontalCuts[i-1];
        maxH = max(h, maxH);
      }
      for(int i=1; i<verticalCuts.size(); i++){
        long long w = verticalCuts[i] - verticalCuts[i-1];
        maxW = max(w, maxW);
      }
      maxH = max(maxH, (long long)(hh-horizontalCuts.back()));
      maxW = max(maxW, (long long)(ww-verticalCuts.back()));
      long long mod = 1e9+7;
      return maxW*maxH%mod;
    }
};