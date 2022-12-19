class Solution {
public:
    bool dfs(vector<vector<int>>&G, int beg, int dest){
      stack<int>st;
      unordered_set<int>visited;
      st.push(beg);
      while(st.size()){
        int currNode = st.top();
        if(currNode == dest)
          return true;
        st.pop();
        visited.insert(currNode);
        for(int n:G[currNode])
          if(!visited.count(n))
            st.push(n);
      }
      return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>>G(n);
      for(auto edge:edges)
        G[edge[0]].push_back(edge[1]),G[edge[1]].push_back(edge[0]);
      return dfs(G, source, destination);
    }
};