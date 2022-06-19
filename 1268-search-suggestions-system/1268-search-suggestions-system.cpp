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
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      trie *obj = new trie();
      for(string word:products)
        obj->insert(word);
      
      vector<vector<string>> ans;
      for(int i=0; i<searchWord.length(); i++){
        vector<string>suggs;
        string prefix = searchWord.substr(0, i+1);
        trie* node = obj->getNode(prefix);
        obj->dfs(node, suggs, "", prefix);
        ans.push_back(suggs);
      }
      return ans;
    }
};