class Solution {
public:
    void dfs(vector<vector<int>>&rooms, vector<bool>&visited, int node){
      if(visited[node] || node == rooms.size())
        return;
      visited[node]=true;
      for(auto n:rooms[node])
        dfs(rooms, visited, n);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      vector<bool>visited(rooms.size());
      dfs(rooms, visited, 0);
      for(int i=0; i<visited.size(); i++)
        if(!visited[i])
          return false;
      return true;
    }
};