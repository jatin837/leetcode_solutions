class Solution {
public:
    vector<string>getWords(string &s){
      vector<string>res;
      string word = "";
      for(auto ch:s){
        if(ch == ' '){
          res.push_back(word);
          word = "";
        }else{
          word += ch;
        }
      }
      res.push_back(word);
      return res;
    }
    bool wordPattern(string pattern, string s) {
      unordered_map<char, int> pmap;
      unordered_map<string, int> smap;
      vector<string>word = getWords(s);
      if(pattern.length() != word.size())
        return false;
      for(int i=0; i<pattern.length(); i++){
        if(pmap[pattern[i]] != smap[word[i]])
          return false;
        pmap[pattern[i]] = i+1;
        smap[word[i]] = i+1;
      }
      return true;
    }
};