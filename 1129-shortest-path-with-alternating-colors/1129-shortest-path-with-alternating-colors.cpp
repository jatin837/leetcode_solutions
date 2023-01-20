class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    // construct a red graph and a blue graph
    // for each graph, traverse from red graph initially and maintain a state which graph current node belongs
    // maintain a visited state to avoid any cycles
    vector<unordered_set<int>>redGraph(n), blueGraph(n);
    vector<int>ret(n, INT_MAX);
    set<pair<int, bool>>visited;
    queue<pair<int, bool>>q;
    for(auto re:redEdges)
      redGraph[re[0]].insert(re[1]);
    for(auto be:blueEdges)
      blueGraph[be[0]].insert(be[1]);
    if(redGraph[0].size())
      q.push({0, false});
    if(blueGraph[0].size())
      q.push({0, true});
    int dist = 0;
    while(q.size()){
      int sz = q.size();
      while(sz--){
        auto [currNode, prevRed] = q.front();
        q.pop();
        ret[currNode] = min(ret[currNode], dist);
        visited.insert({currNode, prevRed});
        if(prevRed){
          for(int nextNode:blueGraph[currNode]){
            pair<int, bool>next = {nextNode, false};
            if(!visited.count(next))
              q.push(next);
          }
        }else{
           for(int nextNode:redGraph[currNode]){
            pair<int, bool>next = {nextNode, true};
            if(!visited.count(next))
              q.push(next);
          }
        }       
      }
      dist++;
    }
    ret[0] = 0;
    for(int i=1; i<n; i++)
      if(ret[i] == INT_MAX)
        ret[i] = -1;
    return ret;
  }
};