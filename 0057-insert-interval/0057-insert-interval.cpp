class Solution {
public:
    // Returns true if the intervals a and b have a common element.
    bool doesIntervalsOverlap(vector<int>& a, vector<int>& b) {
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }
    
    // Return the interval having all the elements of intervals a and b.
    vector<int> mergeIntervals(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    // Insert the interval newInterval, into the list interval keeping the sorting order intact.
    void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        
        if (index != intervals.size()) {
            intervals.insert(intervals.begin() + index, newInterval);
        } else {
            intervals.push_back(newInterval);
        }
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Insert the interval first before merge processing.
        insertInterval(intervals, newInterval);
        
        vector<vector<int>> answer;
        int i=0; int j=0;
        while(j < intervals.size() && i <= j){
            vector<int> currInterval = {intervals[i][0], intervals[i][1]};
            while (j < intervals.size() && doesIntervalsOverlap(currInterval, intervals[j])) {
                currInterval = mergeIntervals(currInterval, intervals[j]);
                j++;
            }
            i = j;
            answer.push_back(currInterval);
        }
        
        return answer;
    }
};
