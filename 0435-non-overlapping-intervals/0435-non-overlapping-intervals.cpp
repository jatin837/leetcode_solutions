class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<int>prev = intervals[0];
      int ret = 0;
      for(int i=1; i<intervals.size(); i++){
        vector<int>curr = intervals[i];
        if(curr[0] < prev[1]){
          ret++;
          if(curr[1] > prev[1])
            continue;
        }
        prev = curr;
      }
      return ret;
    }
};