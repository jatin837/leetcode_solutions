#define SIZE 26
class trie{
  array<trie*, SIZE> nodes;
  bool isEnd = false;
public:
  void insert(string key){
    trie* curr = this;
    for(int i=0; i<key.length(); i++){
      int idx = key[i] - 'a';
      if(curr->nodes[idx] == nullptr)
        curr->nodes[idx] = new trie();
      curr = curr->nodes[idx];
    }
    curr->isEnd = true;
  }
  void print(trie* node){
    if(node == nullptr)
      return;
    for(int i=0; i<26; i++){
      if(node->nodes[i] != nullptr){
        cout<<char('a'+i);
        if(node->nodes[i]->isEnd)
          cout<<'\n';
        print(node->nodes[i]);
      }
    }
  }
  void dfs(trie* node, vector<string>&ans, string tmp, string& prefix){
    if(ans.size() == 3)
      return;
    if(node == nullptr)
      return;
    if(node->isEnd)
      ans.push_back(prefix + tmp);
    for(int i=0; i<26; i++)
      if(node->nodes[i])
        dfs(node->nodes[i], ans, tmp+char('a'+i), prefix);
  }
  trie* getNode(string prefix){
    trie* curr = this;
    for(char ch:prefix){
      int idx = ch - 'a';
      if(curr->nodes[idx] == nullptr)
        return nullptr;
      curr = curr->nodes[idx];
    }
    return curr;
  }
  bool exist(string prefix){
    trie* curr = this;
    for(char ch:prefix){
      int idx = ch - 'a';
      if(curr->nodes[idx] == nullptr)
        return false;
      curr = curr->nodes[idx];
    }
    return true;
  }
};


class Solution {
public:
    static bool cmp(string& ls, string& rs){
      return ls.length() > rs.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
      for(string &word:words)
        reverse(begin(word), end(word));
      sort(begin(words), end(words), cmp);
      trie* obj = new trie();
      obj->insert(words[0]);
      int ans = words[0].length()+1;
      for(int i=0; i<words.size(); i++){
        if(not obj->exist(words[i])){
          obj->insert(words[i]);
          ans += words[i].length()+1;
        }
      }
      return ans;
    }
};
