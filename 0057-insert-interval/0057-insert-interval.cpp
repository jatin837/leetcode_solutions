class Solution {
public:
  bool overlap(vector<int>&p1, vector<int>&p2){
    return p2[0] <= p1[1];
  }
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int indx = lower_bound(begin(intervals), end(intervals), newInterval) - begin(intervals);
    intervals.insert(begin(intervals) + indx, newInterval);
    int b = indx;
    if(b && overlap(intervals[b-1], intervals[b]))
      b -= 1;
    int e = b;
    vector<int>curr = intervals[b];
    while(e < intervals.size() && overlap(curr, intervals[e])){
      curr[0] = min(curr[0], intervals[e][0]);
      curr[1] = max(curr[1], intervals[e][1]);
      e++;
    }
    vector<vector<int>>ret;
    for(int i=0; i<b; i++)
      ret.push_back(intervals[i]);
    ret.push_back(curr);
    for(int i=e; i<intervals.size(); i++)
      ret.push_back(intervals[i]);
    return ret;
  }
};
