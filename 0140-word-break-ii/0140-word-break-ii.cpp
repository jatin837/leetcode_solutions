class Solution {
public:
  vector<string>ret;
  void backtrack(string& s, int pos, string curr, unordered_set<int>& step, unordered_map<string, bool>&exist){
    if(pos == s.length()){
      ret.push_back(curr);
      return;
    }
    for(int dd:step){
      if(pos+dd > s.length())
        continue;
      string currPrefix = s.substr(pos, dd);
      if(exist[currPrefix]){
        if(curr == "")
          backtrack(s, pos+dd, curr+currPrefix, step, exist);
        else
          backtrack(s, pos+dd, curr+" "+currPrefix, step, exist);
      }
    }
  }
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool>exist;
    unordered_set<int>step;
    for(string word:wordDict){
      exist[word] = true;
      step.insert(word.length());
    }
    backtrack(s, 0, "", step, exist);
    return ret;
  }
};