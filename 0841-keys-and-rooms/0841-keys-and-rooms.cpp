class Solution {
public:
  unordered_set<int>visited;
  void dfs(vector<vector<int>>&rooms, int room){
    visited.insert(room);
    for(int next:rooms[room])
      if(!visited.count(next))
        dfs(rooms, next);
  }
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    dfs(rooms, 0);
    return visited.size() == rooms.size();
  }
};