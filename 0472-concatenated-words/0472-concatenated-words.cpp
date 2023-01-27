class Solution {
public:
  bool isConcatenated(string& s, unordered_set<string>&dict){
    const int length = s.length();
    vector<bool> dp(length + 1);
    dp[0] = true;
    for (int i = 1; i <= length; ++i)
      for (int j = (i == length ? 1 : 0); j < i; ++j)
        if(!dp[i])
          dp[i] = dp[j] && dict.count(s.substr(j, i - j));
    return dp[length];
  }
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());
    vector<string> ret;
    for (string word : words)
      if(isConcatenated(word, dict))
        ret.push_back(word);
    return ret;
  }
};