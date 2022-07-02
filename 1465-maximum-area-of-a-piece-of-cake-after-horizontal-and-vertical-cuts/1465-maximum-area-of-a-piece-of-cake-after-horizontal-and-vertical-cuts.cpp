class Solution {
public:
    int maxArea(int hh, int ww, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      sort(horizontalCuts.begin(), horizontalCuts.end());
      sort(verticalCuts.begin(), verticalCuts.end());
      horizontalCuts.push_back(hh);
      verticalCuts.push_back(ww);
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
      long long mod = 1e9+7;
      return maxW*maxH%mod;
    }
};