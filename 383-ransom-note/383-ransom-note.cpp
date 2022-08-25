class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int>given;
      unordered_map<char, int>required;
      for(auto ch:ransomNote)
        required[ch]++;
      for(auto ch:magazine)
        given[ch]++;
      for(auto [ch, cnt]:required)
        if(given[ch] < cnt)
          return false;
      return true;
    }
};