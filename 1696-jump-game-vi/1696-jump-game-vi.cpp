class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      priority_queue<pair<int, int>> pq;
      pq.push({nums[0], 0});
      for(int i=1; i<nums.size(); i++){
        while(pq.top().second <= i-k-1)
          pq.pop();
        nums[i] += pq.top().first;
        pq.push({nums[i], i});
      }
      return nums.back();
    }
};