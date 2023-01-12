typedef vector<vector<int>> G;
typedef vector<array<int, 26>> CNT;

class Solution {
public:
  void add(array<int, 26>&a, array<int, 26>&b){
    for(int i=0; i<26; i++)
      a[i] += b[i];
  }
  void dfs(int node, int parent, G& g, string& labels, CNT& cnt){
    for(int n:g[node])
      if(n != parent)
        dfs(n, node, g, labels, cnt);
    for(int n:g[node])
      if(n != parent)
        add(cnt[node], cnt[n]);
  }
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    G g(edges.size()+1);
    CNT cnt(edges.size()+1);
    for(auto e:edges){
      g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
      cnt[e[0]][labels[e[0]]-'a'] = 1, cnt[e[1]][labels[e[1]]-'a'] = 1;
    }
    dfs(0, -1, g, labels, cnt);
    vector<int>ret(edges.size()+1);
    for(int i=0; i<cnt.size(); i++)
      ret[i] = cnt[i][labels[i]-'a'];
    return ret;
  }
};