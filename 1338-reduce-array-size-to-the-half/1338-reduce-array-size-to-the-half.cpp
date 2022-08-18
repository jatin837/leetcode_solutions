class Solution {
public:
    int minSetSize(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      int b = 0;
      int e = 0;
      priority_queue<int>pq;
      while(e<arr.size() && b < arr.size()){
        int curr = arr[b];
        while(e < arr.size() && arr[e] == arr[b])
          e++;
        pq.push(e-b);
        b = e;
      }
      int ans = 0;
      int cnt = 0;
      while(!pq.empty() && cnt < (arr.size())>>1){
        cnt += pq.top();
//        cout<<pq.top()<<' ';
        pq.pop();
        ans++;
      }
      return ans;
    }
};