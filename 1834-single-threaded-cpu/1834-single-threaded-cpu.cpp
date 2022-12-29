class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& A) {
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    int N = A.size();
    long long time = 0, i = 0;
    for (int i = 0; i < N; ++i)
      A[i].push_back(i);
    sort(begin(A), end(A));
    vector<int> ans;
    while (i < N || pq.size()) {
      while (i < N && A[i][0] <= time){
        pq.push({A[i][1], A[i][2]});
        i++;
      }
      if(pq.empty()){
        time = A[i][0];
        continue;
      }
      auto [procTime, indx] = pq.top();
      pq.pop();
      time += procTime;
      ans.push_back(indx);
    }
    return ans;
  }
};