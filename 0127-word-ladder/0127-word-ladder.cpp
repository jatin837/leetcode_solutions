class Solution {
public:
    unordered_map<string, set<string>>buildGraph(vector<string>& wordList){
      unordered_map<string, set<string>>G;
      for(string word:wordList){
        for(int i=0; i<word.size(); i++){
          string tmp = word;
          tmp[i] = '*';
          G[tmp].insert(word);
        }
      }
      return G;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      queue<pair<string, int>>q;
      unordered_set<string>visited;
      q.push({beginWord, 0});
      unordered_map<string, set<string>>G = buildGraph(wordList);
      while(q.size()){
        auto [currWord, dist] = q.front();
        q.pop();
        visited.insert(currWord);
        if(currWord == endWord)
          return dist+1;
        for(int i=0; i<currWord.size(); i++){
          string tmp = currWord;
          tmp[i] = '*';
          for(auto s:G[tmp])
            if(!visited.count(s))
              q.push({s, dist+1});
        }
      }
      return 0;
    }
};