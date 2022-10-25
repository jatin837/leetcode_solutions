class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      string a, b;
      for(string word:word1)
        a += word;
      for(string word:word2)
        b += word;
      return a == b;
    }
};