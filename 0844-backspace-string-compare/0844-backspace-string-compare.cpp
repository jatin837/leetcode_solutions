class Solution {
public:
    string getWord(string& s1){
      stack<char>st;
      for(int i=0; i<s1.length(); i++){
        if(s1[i] == '#'){
          if(st.size())
            st.pop();
          continue;
        }
        st.push(s1[i]);
      }
      string ret = "";
      while(st.size()){
        ret += st.top();
        st.pop();
      }
      return ret;
    }
    bool backspaceCompare(string s, string t) {
      return getWord(s) == getWord(t);
    }
};