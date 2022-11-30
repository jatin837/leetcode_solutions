class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>cnt;
        for(int n:arr)
            cnt[n]++;
        unordered_set<int>st;
        for(auto [x, y]:cnt)
            if(st.count(y))
                return false;
            else
                st.insert(y);
        return true;
    }
};