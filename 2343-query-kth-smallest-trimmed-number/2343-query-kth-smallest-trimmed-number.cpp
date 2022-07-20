class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        for(auto &q:queries) {
            vector<pair<string,int>> pq;
            int start = nums[0].size()-q[1];
            for(int i=0;i<n; i++)
                pq.push_back({nums[i].substr(start), i});
            sort(pq.begin(), pq.end());
            res.push_back(pq[q[0]-1].second);
        }
        return res;
    }
};