class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
      int b = 0;
      int e = 0;
      int ans = 0;
      vector<long long>pre(chargeTimes.size()+1, 0);
      priority_queue<pair<int, int>>pq;
      for(int i=0; i<chargeTimes.size(); i++)
        pre[i+1] = pre[i] + runningCosts[i];
      while(e < runningCosts.size()){
        pq.push({chargeTimes[e], e});
        while(pq.top().second < b)
          pq.pop();
        int currMax = pq.top().first;
        if(currMax+(e-b+1)*(pre[e+1]-pre[b]) <= budget)
          ans = max(ans, e-b+1); 
        else
          b++;
        e++;
      }
      return ans;
    }
};