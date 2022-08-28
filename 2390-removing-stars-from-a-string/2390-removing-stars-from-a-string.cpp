//class Solution {
//public:
//    string removeStars(string s) {
//      int i=0;
//      while(i<s.length()){
//        if(s[i] == '*'){
//          s.erase(i-1,2);
//          i--;
//          continue;
//        }
//        i++;
//      }
//      return s;
//    }
//};

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto c: s){
            if(c == '*'){
                st.pop();
                continue;
            }else st.push(c);
        }
        string ans(st.size(), 'x');
        int i=st.size();
        while(!st.empty()){
            ans[--i] = st.top();
            st.pop();
        }
        return ans;
    }
};