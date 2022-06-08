class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int s = newInterval[0];
      int e = newInterval[1];
      int len = intervals.size();
      vector<vector<int>> ans;
      int i=0;
      
      while(i < len and s > intervals[i][1])
        ans.push_back(intervals[i++]);
      
      while(i<len and e>=intervals[i][0]){
        s = min(s, intervals[i][0]);
        e = max(e, intervals[i][1]);
        i++;
      }
      ans.push_back({s, e});
      
      while(i++<len)
        ans.push_back(intervals[i-1]);
      return ans;
    }
};