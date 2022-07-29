class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      unordered_map<char, int> mp1;
      unordered_map<char, int> mp2;
      vector<string>ans;
      for(string word:words){
        int i=0;
        while(i<word.length() and mp1[word[i]] == mp2[pattern[i]]){
          mp1[word[i]]=i+1;
          mp2[pattern[i]]=i+1;
          i++;
        }
        mp1.clear();
        mp2.clear();
        if(i==word.length())
          ans.push_back(word);
      }
      return ans;
    }
};