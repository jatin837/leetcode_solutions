class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      queue<vector<int>>q;
      q.push({0});
      vector<vector<int>>ret;
      while(!q.empty()){
        queue<vector<int>>q2;
        while(!q.empty()){
          auto top = q.front();
          for(int n:top)
            cout<<n<<' ';
          cout<<'\n';
          q.pop();
          int currNode = top.back();
          if(currNode == graph.size()-1)
            ret.push_back(top);
          for(int nxtNode:graph[currNode]){
            vector<int>newList = vector<int>(top.begin(), top.end());
            newList.push_back(nxtNode);
            q2.push(newList);
          }
        }
        q=q2; 
      }
      return ret;
    }
};