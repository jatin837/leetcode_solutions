class Solution {
public:
    bool check(int idx, string &s, vector<string>& words, unordered_map<string, int>&wordCnt){
      int wordLen = words[0].length();
      int tot_words = words.size();
      string sub_str = s.substr(idx, wordLen*tot_words);
      unordered_map<string, int> mp;
      for(int i=0; i<tot_words; i++){
        string w = sub_str.substr(wordLen*i, wordLen); 
        if(wordCnt[w] == 0)
          return false;
        mp[w]++;
      }
      for(auto word:words){
        if(mp[word] != wordCnt[word])
          return false;
      }
      return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
      unordered_map<string, int>wordCnt;
      for(auto word:words)
        wordCnt[word]++;
      
      int wordLen = words[0].length();
      int tot_words = words.size();
      
      vector<int>ans;
      for(int i=0; i<s.length() - wordLen*tot_words+1; i++){
        if(check(i, s, words, wordCnt))
          ans.push_back(i); 
      }
      return ans;
    }
};