class Solution {
public:
    int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
      vector<pair<int, int>>effsp(n);
      priority_queue<long long, vector<long long>, greater<long long>>pq;
      for(int i=0; i<n; i++)
        effsp[i] = {eff[i], sp[i]};
      sort(rbegin(effsp), rend(effsp));
      long long ans = 0;
      long long totSpeed = 0;
      for(auto [eff, sp]:effsp){
        totSpeed += sp;
        pq.push(sp);
        if(pq.size() > k){
          totSpeed -= pq.top();
          pq.pop();
        }
        ans = max(ans, totSpeed*eff);
      }
      return ans%mod;
    }
};