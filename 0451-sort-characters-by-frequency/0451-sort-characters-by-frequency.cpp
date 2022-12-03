class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>cnt;
        for(char ch:s)
            cnt[ch]++;
        
        vector<pair<int, char>>pairOfCountChar;
        
        for(auto [x,y]:cnt)
            pairOfCountChar.push_back({y, x});
        
        sort(pairOfCountChar.rbegin(), pairOfCountChar.rend());
        
        string ret = "";
        for(auto [cnt, ch]:pairOfCountChar)
            for(int i=0; i<cnt; i++)
                ret += ch;
        
        return ret;
    }
};