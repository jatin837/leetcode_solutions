class Solution {
public:
    string makeGood(string s) {
      stack<char>st;
      for(int i=0; i<s.length(); i++){
        if(!st.empty() && (st.top()^s[i]) == 32){
          st.pop();
          continue;
        }
        st.push(s[i]);
      }
      string ret = "";
      while(!st.empty()){
        ret += st.top();
        st.pop();
      }
      reverse(ret.begin(), ret.end());
      return ret;
    }
};