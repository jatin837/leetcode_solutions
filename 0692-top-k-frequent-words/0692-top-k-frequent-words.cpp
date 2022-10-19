class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;
    for(string& word : words)
      mp[word] -= 1;
    priority_queue<pair<int, string>> pq;
    for(auto [word, cnt]:mp) {
      pq.push({cnt, word});
      if(pq.size() > k) 
        pq.pop();
    }
    vector<string> res(k);
    while(!pq.empty() && k >= 0) {
      res[--k] = pq.top().second;
      pq.pop();
    }
    return res;
  }
};