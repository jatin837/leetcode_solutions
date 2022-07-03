class Solution {
public:
    vector<int> diStringMatch(string s) {
      int l = 0;
      int h = s.length();
      vector<int>ans;
      for(char ch:s){
        if(ch == 'I')
          ans.push_back(l++);
        else
          ans.push_back(h--);
      }
      ans.push_back(h);
      return ans;
    }
};