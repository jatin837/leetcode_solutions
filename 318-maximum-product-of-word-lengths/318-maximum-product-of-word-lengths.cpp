class Solution {
public:
    bool valid(string &s, array<bool, 26>&fq){
      for(char ch:s)
        if(fq[ch-'a'])
          return false;
      return true;
    }
    int maxProduct(vector<string>& words) {
      vector<array<bool, 26>>mp(words.size());
      int ans = 0;
      for(int i=0; i<words.size(); i++){
        for(char ch:words[i])
          mp[i][ch-'a']=true;
        for(int j=0; j<i; j++)
          if(valid(words[j], mp[i]))
            ans = max(ans, int(words[i].length()*words[j].length()));
      }
      return ans;
    }
};