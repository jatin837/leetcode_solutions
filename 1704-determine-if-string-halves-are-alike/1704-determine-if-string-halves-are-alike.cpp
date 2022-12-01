class Solution {
public:
    int cntVwl(string& s){
        unordered_set<char>st;
        st = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        int cnt=0;
        for(char ch:s)
            cnt += st.count(ch);
        return cnt;
    }
    bool halvesAreAlike(string s) {
        string lh = s.substr(0, s.length()/2);
        string rh = s.substr(s.length()/2);
        return cntVwl(lh) == cntVwl(rh);
    }
};