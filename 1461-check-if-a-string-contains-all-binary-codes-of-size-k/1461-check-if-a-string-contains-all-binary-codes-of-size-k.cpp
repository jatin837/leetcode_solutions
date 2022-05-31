class Solution {
public:
    bool hasAllCodes(string s, int k) {
      set<string>st;
      for(int i=0; i<s.length(); i++){
        if(i+k-1<s.length()){
          st.insert(s.substr(i, k));
        }
      }
      if(st.size() == 1<<k)
        return true;
      return false;
    }
};