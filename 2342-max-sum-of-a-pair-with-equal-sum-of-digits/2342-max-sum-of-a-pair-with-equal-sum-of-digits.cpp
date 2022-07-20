class Solution {
public:
    int digSum(int num){
      int ans = 0;
      while(num){
        ans += num%10;
        num/=10;   
      }
      return ans;
    }
    int maximumSum(vector<int>& nums) {
      unordered_map<int, priority_queue<int>>mp;
      int ans = -1;
      for(int num:nums){
        mp[digSum(num)].push(-num);
        if(mp[digSum(num)].size()>2)
          mp[digSum(num)].pop();
      }
      for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second.size() == 2){
          int x = -it->second.top();
          it->second.pop();
          int y = -it->second.top();
          it->second.pop();
          ans = max(x+y, ans);
        }
      }
      return ans;
    }
};