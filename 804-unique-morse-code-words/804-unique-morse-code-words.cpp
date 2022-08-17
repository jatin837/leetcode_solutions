class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
      array<string, 26>char2morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
      unordered_set<string>seen;
      for(string word:words){
        string curr = "";
        for(char ch:word)
          curr += char2morse[ch-'a'];
        cout<<curr<<'\n';
        seen.insert(curr);
      }
      return seen.size();
    }
};