class Solution {
public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    if(x == 0)
      return 0;
    set<pair<int, bool>>visited;
    for(auto n:forbidden)
      visited.insert({n, true}),visited.insert({n, false});
    queue<pair<int, bool>>q;
    q.push({0, false});
    visited.insert({0, false});
    visited.insert({0, true});
    int jmpcnt = 0;
    while(q.size()){
      int sz = q.size();
      while(sz--){
        auto [currPos, back] = q.front();
        q.pop();
        if(currPos == x)
          return jmpcnt;
        pair<int, bool>forwardJump = {currPos+a, false};
        pair<int, bool>backwardJump = {currPos-b, true};
        if(visited.count(forwardJump) == 0 and forwardJump.first < 7000){
          q.push(forwardJump);
          visited.insert(forwardJump);
        }
        if(!back and visited.count(backwardJump) == 0 and backwardJump.first > 0){
          q.push(backwardJump);       
          visited.insert(backwardJump);
        }
      }
      jmpcnt++;
    }
    return -1;
  }
};
