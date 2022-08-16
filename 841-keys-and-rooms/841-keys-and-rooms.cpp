class Solution {
public:
    void dfs(vector<vector<int>>&rooms, unordered_set<int>&visited, int node){
      if(visited.count(node))
        return;
      visited.insert(node);
      for(auto n:rooms[node])
        dfs(rooms, visited, n);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      unordered_set<int>visited;
      dfs(rooms, visited, 0);
      return visited.size() == rooms.size();
    }
};