typedef vector<vector<int>> G;
typedef vector<array<int, 26>> CNT;
class Solution {
public:
  // adds the frequency array of child to parent's frequency array;
  void add(array<int, 26>&a, array<int, 26>&b){
    for(int i=0; i<26; i++)
      a[i] += b[i];
  }
  // postorder traversal, first update frequency array of each child, then the parent accordingly by adding frequency of it's child
  // By "adding", I mean vector addition.
  void dfs(int node, int parent, G& g, string& labels, CNT& cnt){
    for(int n:g[node])
      if(n != parent)
        dfs(n, node, g, labels, cnt);
    for(int n:g[node])
      if(n != parent)
        add(cnt[node], cnt[n]);
  }
  // Build The graph from edge list and initialize the counter(stored as cnt)
  void buildGraph(G& edges, CNT& cnt, string& labels, G& g){
    for(auto e:edges){
      g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
      cnt[e[0]][labels[e[0]]-'a'] = 1, cnt[e[1]][labels[e[1]]-'a'] = 1;
    }   
  }
  // Main function
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    G g(edges.size()+1);
    CNT cnt(edges.size()+1);
    
    // build the graph and init the counter
    buildGraph(edges, cnt, labels, g);
    
    // Do a postorder tree walk on the tree to computer the counter
    dfs(0, -1, g, labels, cnt);

    // now, counter that all the information we need
    // just create a return variable to extract that information
    vector<int>ret(edges.size()+1);
    for(int i=0; i<cnt.size(); i++)
      ret[i] = cnt[i][labels[i]-'a'];
    return ret;
  }
};