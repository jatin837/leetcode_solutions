class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
      int b = 0;
      int e = 0;
      int ans = 0;
      long long sum = 0;
      priority_queue<pair<int, int>>pq;
      while(e < runningCosts.size()){
        sum += runningCosts[e];
        pq.push({chargeTimes[e], e});
        while(pq.top().second < b)
          pq.pop();
        int currMax = pq.top().first;
        if(currMax+(e-b+1)*sum <= budget)
          ans = max(ans, e-b+1); 
        else
          sum -= runningCosts[b++];
        e++;
      }
      return ans;
    }
};