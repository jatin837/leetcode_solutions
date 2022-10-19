class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap;
        for(string& word : words) {
            hashmap[word] -= 1;
        }
        priority_queue<pair<int, string>> pq;
        for(auto [word, cnt]:hashmap) {
            pq.push({cnt, word});
            if(pq.size() > k) 
              pq.pop();
        }
        vector<string> res;
        while(!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }
private:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
};