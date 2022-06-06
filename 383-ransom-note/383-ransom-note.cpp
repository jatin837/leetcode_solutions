class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int>freq1;
      unordered_map<char, int>freq2;
      for(auto ch:ransomNote)
        freq1[ch]++;
      for(auto ch:magazine)
        freq2[ch]++;
      for(auto it=freq1.begin(); it!=freq1.end(); it++){
        char ch = it->first;
        int cnt = it->second;
        if(freq2[ch] < cnt)
          return false;
      }
      return true;
    }
};