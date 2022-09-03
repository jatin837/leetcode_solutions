class Solution {
public:
    vector<int>ret;
    void dfs(int num, int len, int k, int n){
      if(len == n){
        ret.push_back(num);  
        return;
      }
      if(num%10 + k < 10)
        dfs(10*num+num%10+k, len+1, k, n);
      if(k && num%10 - k >= 0)
        dfs(10*num + num%10 - k, len+1, k, n);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
      for(int i=1; i<=9; i++)
        dfs(i, 1, k, n);
      return ret;
    }
};