class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> bucketBelong;
        for(char ch:s)
            bucketBelong[ch]++;
        vector<set<char>> bucket(s.length()+1);
        for(auto [ch, buck]:bucketBelong)
            bucket[buck].insert(ch);
        string ret = "";
        for(int i=s.length(); i>=0; i--)
            for(char ch:bucket[i])
                for(int len=0; len<i; len++)
                    ret += ch;
        return ret;
    }
};