class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    // Put all words in a set
    unordered_set<string> dictionary(words.begin(), words.end());
    // This will be our final answer
    vector<string> answer;
    // for every word, check if it's a concatented word
    for (const string& word : words) {
      const int length = word.length();
      // to check if current word is concatenated, we use dynamic programming
      vector<bool> dp(length + 1);
      // empty string is a concatenated string :-(
      dp[0] = true;
      
      // this is a bit magical, but I'll try to decipher it 
      for (int i = 1; i <= length; ++i)
        // okay, j will run for i = 0 or 1 depending on weather i is equal to length or not
        for (int j = (i == length ? 1 : 0); j < i; ++j)
          if(!dp[i])
            dp[i] = dp[j] && dictionary.count(word.substr(j, i - j));
      
      // if current word is concatenated, put it in our final answer
      if (dp[length])
        answer.push_back(word);
    }
    // finally return the answer
    return answer;
  }
};