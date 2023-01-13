class Solution {
public:
  int gret = 0;
  int dfs(int node, vector<vector<int>>&G, string &s){
    int ret = 1;
    priority_queue<int>pq;
    for(int child:G[node]){
      int child_cost = dfs(child, G, s);
      if(s[child] == s[node])
        continue;
      pq.push(child_cost);
    }
    if(pq.size() == 0){
      gret = max(gret, ret);
      return ret;
    }
    if(pq.size() == 1){
      ret += pq.top();
      gret = max(ret, gret);
      return ret;
    }
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ret += max(a, b);
    gret = max(a + b + 1, gret);
    return ret;
  }
  int longestPath(vector<int>& parent, string s) {
    // Build the Tree(the adjacency List)
    vector<vector<int>>G(parent.size());
    for(int i=1; i<parent.size(); i++)
      G[parent[i]].push_back(i);
    // perform a BFS
    // If the next node and current node has different label, then, we move to add it to the queue
    dfs(0, G, s);
    return gret;
  }
};