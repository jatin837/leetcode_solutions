class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string, vector<string>> fq;
      for(auto s:strs){
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        fq[tmp].push_back(s); 
      }
      vector<vector<string>>ans;
      for(auto it=fq.begin(); it!=fq.end(); it++)
        ans.push_back(it->second);
      return ans;
    }
};