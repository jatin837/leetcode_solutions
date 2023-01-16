class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int s = newInterval[0];
      int e = newInterval[1];
      int len = intervals.size();
      vector<vector<int>> ans;
      int i=0;
      
      // Insert all  the points to our answer which ends earlier than our newIntervals start
      while(i < len and s > intervals[i][1])
        ans.push_back(intervals[i++]);
      
      // update our newInterval before adding it to answer
      // basically, we need to skip all the intervals which ends before current interval ends
      while(i<len and e>=intervals[i][0]){
        s = min(s, intervals[i][0]);
        e = max(e, intervals[i][1]);
        i++;
      }
      ans.push_back({s, e});
      
      while(i<len)
        ans.push_back(intervals[i++]);
      return ans;
    }
};