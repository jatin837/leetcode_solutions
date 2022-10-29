class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
      vector<pair<int,int>>grow_plant_time;
      
      for(int i=0; i<plantTime.size(); i++)
        grow_plant_time.push_back({growTime[i], plantTime[i]});
      
      sort(grow_plant_time.rbegin(), grow_plant_time.rend());
      
      int days = grow_plant_time[0].first+grow_plant_time[0].second+1;
      int p0 = grow_plant_time[0].second;
      
      for(int i=1; i<grow_plant_time.size(); i++){
        auto [g, p] = grow_plant_time[i];
        days += max(0, (g+p+p0+1)-days);
        p0 += p;
      }
      return days-1;
    }
};