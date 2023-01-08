class Solution {
  int gcd(int a, int b) {
    while (b) {
      a = a % b;
      swap(a, b);
    }
    return a;
  } 
  string slope(int x1, int x2, int y1, int y2){
    int g = gcd(y1-y2, x1-x2);
    string dy_dx = to_string((y1-y2)/g) + "_" + to_string((x1-x2)/g);
    return dy_dx;
  }
public:
    int maxPoints(vector<vector<int>>& points) {
      int ret = 1;
      for(int i=0; i<points.size(); i++){
        unordered_map<string, int> mp;
        for(int j=0; j<points.size(); j++){
          if(j == i)
            continue;
          string dy_dx = slope(points[i][0], points[j][0], points[i][1], points[j][1]);
          mp[dy_dx]++;
        }
        for(auto [m, cnt]:mp)
          ret = max(ret, cnt+1);
      }
      return ret;
    }
};