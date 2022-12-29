class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
      priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>pq;
      vector<int>ret;
      for(int i=0; i<tasks.size(); i++)
        tasks[i].push_back(i);
      sort(begin(tasks), end(tasks));
      long long i=0, time=0;
      while(pq.size() || i < tasks.size()){
        while(i < tasks.size() && tasks[i][0] <= time){
          pq.push({tasks[i][1], tasks[i][2]});
          i++;
        }
        if(pq.empty()){
          time = tasks[i][0];
          continue;
        }
        auto [procTime, indx] = pq.top();
        pq.pop();
        time += procTime;
        ret.push_back(indx);
      }
      return ret;
    }
};