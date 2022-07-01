class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> fq;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      for(int num:nums)
        fq[num]++;
      for(auto it=fq.begin(); it!=fq.end(); it++){
        pq.push({it->second, it->first});
        if(pq.size() > k)
          pq.pop();
      }
      vector<int>res;
      while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
      }
      return res;
    }
};