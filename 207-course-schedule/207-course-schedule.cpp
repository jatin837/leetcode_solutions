class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prereq) {
    vector<vector<int>>G(numCourses);
    for(auto e:prereq){
      if(e[0] == e[1])
        return false;
      G[e[1]].push_back(e[0]);
    }
    vector<int>degree(numCourses, 0);
    for(int i=0; i<numCourses; i++)
      for(int n:G[i])
        degree[n]++;
    queue<int>q;
    for(int i=0; i<numCourses; i++)
      if(degree[i] == 0)
        q.push(i);
    if(q.size()==0)
      return false;
    while(!q.empty()){
      int x = q.front();
      q.pop();
      for(int n:G[x]){
        degree[n]--;
        if(degree[n] == 0)
          q.push(n);
        if(degree[n] == -1)
          return false;
      }
    }
    for(int n:degree)
      if(n != 0)
        return false;
    return true;
  }
};