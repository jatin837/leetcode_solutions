class Solution {
public:
    int largestCombination(vector<int>& candidates) {
      int ans = 0;
      for(int i=0; i<31; i++){
        int cnt = 0;
        for(auto num:candidates)
          cnt += bool((num)&(1<<i)); 
        ans = max(ans, cnt);
      }
      return ans;
    }
};