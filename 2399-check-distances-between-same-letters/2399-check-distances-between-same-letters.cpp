class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
      int mp[26] = {0};
      for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(mp[ch-'a']==0){
          mp[ch-'a']=i+1;
          continue;
        }
        int dist = i-mp[ch-'a'];
        if(distance[ch-'a'] != dist)
          return false;
      }
      return true;
    }
};