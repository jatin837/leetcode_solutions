class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> orderMap;
    orderMap[' '] = -1;
    for(int i=0; i<26; i++)
      orderMap[order[i]] = i;
    for(int i=0; i<words.size()-1; i++){
      if(words[i] == words[i+1])
        continue;
      int j=0;
      while(j < min(words[i].length(), words[i+1].length()) && words[i][j] == words[i+1][j])
        j++;
      char ch1 = ' ', ch2 = ' ';
      if(j < words[i].length())
        ch1 = words[i][j];
      if(j < words[i+1].length())
        ch2 = words[i+1][j];
      if(orderMap[ch1] > orderMap[ch2])
        return false;
    }
    return true;
  }
};