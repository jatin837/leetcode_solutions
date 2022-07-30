class Solution {
public:
    bool isSuperSet(unordered_map<char, int>& mp1, unordered_map<char, int>& mp2){
      for(auto [ch,fq]:mp2){
        if(mp1[ch]<fq)
          return false;
      }
      return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      unordered_map<char, int>mp1;
      for(string word:words2){
        unordered_map<char, int>mp2;
        for(char ch:word)
          mp2[ch]++;
        for(auto [ch, fq]:mp2)
          mp1[ch] = max(mp1[ch], fq);
      }
      vector<string>ans;
      for(string word:words1){
        unordered_map<char, int>mp2;
        for(char ch:word)
          mp2[ch]++;
        if(isSuperSet(mp2, mp1))
          ans.push_back(word);
      }
      return ans;
    }
};