class Solution {
public:
    vector<int>top_sort(vector<unordered_set<int>>&G){
      vector<int>degree(G.size(), 0);
      for(int i=1; i<G.size(); i++){
        for(auto n:G[i])
          degree[n]++;
      }
      queue<int>q;
      for(int i=1; i<G.size(); i++)
        if(degree[i]==0)
          q.push(i);
      vector<int>ordering;
      while(!q.empty()){
        int curr = q.front();
        q.pop();
        ordering.push_back(curr);
        for(int n:G[curr]){
          degree[n]--;
          if(degree[n]==-1)
            return {};
          if(degree[n]==0)
            q.push(n);
        }
      }
      return ordering;
    }
    vector<unordered_set<int>> build_DAG(vector<vector<int>>& edges, int k){
      vector<unordered_set<int>>G(k+1);
      for(auto edge:edges)
        G[edge[0]].insert(edge[1]);
      return G;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
      vector<unordered_set<int>> Gr = build_DAG(rowConditions, k);
      vector<int>ord_r = top_sort(Gr);
      vector<unordered_set<int>> Gc = build_DAG(colConditions, k);
      vector<int>ord_c = top_sort(Gc);
      if(ord_r.size() != k || ord_c.size() != k)
        return {};
      unordered_map<int, int>ridx, cidx; 
      for(int i=0; i<k; i++)
        ridx[ord_r[i]]=i, cidx[ord_c[i]]=i;  
      vector<vector<int>>ret(k, vector<int>(k, 0));
      for(int n:ord_r)
        ret[ridx[n]][cidx[n]]=n;
      return ret; 
    }
};