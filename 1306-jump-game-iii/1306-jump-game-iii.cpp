class Solution {
public:
    unordered_set<int>visited;
    bool canReach(vector<int>& arr, int pos) {
      if(pos < 0 or pos >= arr.size())
        return false;
      if(visited.count(pos))
        return false;
      visited.insert(pos);
      if(arr[pos] == 0)
        return true;
      return canReach(arr, pos-arr[pos]) or canReach(arr, pos+arr[pos]);
    }
};