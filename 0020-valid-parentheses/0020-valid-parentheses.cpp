class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char, char>mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        for(auto ch:s){
            if(ch == ')' || ch == '}' || ch == ']'){
                if(st.empty() || mp[st.top()] != ch)
                    return false;
                st.pop();
                continue;
            }
            st.push(ch);
        }
        return st.empty();
    }
};