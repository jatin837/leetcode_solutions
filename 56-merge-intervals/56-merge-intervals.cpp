class Solution {
public:
    bool canBeMerged(vector<int>&int1, vector<int>&int2){
      return int2[0] <= int1[1];
    }
    vector<int> mergeTwo(vector<int>&int1, vector<int>&int2){
      return {min(int1[0], int2[0]), max(int2[1], int1[1])};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(begin(intervals), end(intervals));
      vector<vector<int>> newIntervals;
      newIntervals.push_back(intervals[0]);
      for(int i=1; i<intervals.size(); i++){
        if(canBeMerged(newIntervals[newIntervals.size()-1], intervals[i])){
          vector<int>newIntrvl = mergeTwo(intervals[i], newIntervals[newIntervals.size()-1]);
          newIntervals.pop_back();
          newIntervals.push_back(newIntrvl);
        }else
          newIntervals.push_back(intervals[i]);
      }
      return newIntervals;
    }
};