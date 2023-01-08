class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int ret = 1;
      for(int i=0; i<points.size(); i++){
        unordered_map<double, int> mp;
        for(int j=0; j<points.size(); j++){
          if(j != i){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            double m = atan2((y1-y2),(x1-x2));
            mp[m]++;
          }
        }
        for(auto [x, y]:mp)
          ret = max(ret, y+1);
      }
      return ret;
    }
};