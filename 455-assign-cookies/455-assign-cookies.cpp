class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      int i=0;int j=0;
      int ans = 0;
      sort(g.begin(), g.end());
      sort(s.begin(), s.end());
      while(i<g.size() and j<s.size()){
        if(s[j] >= g[i]){
          i++;j++; 
          ans++;
        }
        else
          j++;
      }
      return ans;
    }
};