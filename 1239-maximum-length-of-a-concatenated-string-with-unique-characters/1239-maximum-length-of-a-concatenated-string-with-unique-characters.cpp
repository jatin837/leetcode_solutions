class Solution {
public:
  int ret = 0;
  void dfs(vector<string>& arr, int pos, int curr){
    if(pos == arr.size()){
      if(__builtin_popcount(curr) > ret)
        ret = __builtin_popcount(curr);
      return;
    }
    int next = curr;
    for(auto ch:arr[pos]){
      if((next&(1<<(ch-'a')))){
        dfs(arr, pos+1, curr);
        return;
      }
      next |= 1<<(ch-'a');
    }
    dfs(arr, pos+1, curr);
    dfs(arr, pos+1, next);
  }
  int maxLength(vector<string>& arr) {
    dfs(arr, 0, 0);
    return ret;
  }
};