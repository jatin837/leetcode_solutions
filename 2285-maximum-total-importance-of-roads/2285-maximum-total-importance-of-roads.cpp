class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      vector<long long>weights(n, 0);
      long long ans = 0;
      for(auto road:roads){
        weights[road[0]]++;
        weights[road[1]]++;
      }
      sort(weights.begin(), weights.end());
      for(int i=0; i<weights.size(); i++)
        ans += weights[i]*(i+1);
      return ans;
    }
};