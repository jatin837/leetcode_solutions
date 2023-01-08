class Solution {
  int gcd(int a, int b) {
    while (b) {
      a = a % b;
      swap(a, b);
    }
    return a;
} 
public:
    int maxPoints(vector<vector<int>>& points) {
      int ret = 1;
      for(int i=0; i<points.size(); i++){
        unordered_map<string, int> mp;
        for(int j=0; j<points.size(); j++){
          if(j != i){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            int g = gcd(y1-y2, x1-x2);
            string dy_dx = to_string((y1-y2)/g) + "_" + to_string((x1-x2)/g);
            mp[dy_dx]++;
          }
        }
        for(auto [m, cnt]:mp)
          ret = max(ret, cnt+1);
      }
      return ret;
    }
};