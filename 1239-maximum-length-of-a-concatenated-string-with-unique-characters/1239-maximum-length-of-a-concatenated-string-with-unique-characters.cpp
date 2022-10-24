class Solution {
public:
  int ret = 0;
  void dfs(vector<string>& arr, int pos, unordered_set<char> curr){
    if(pos == arr.size()){
      if(curr.size() > ret)
        ret = curr.size();
      return;
    }
    unordered_set<char>next(curr.begin(), curr.end());
    for(auto ch:arr[pos]){
      if(next.count(ch)){
        dfs(arr, pos+1, curr);
        return;
      }
      next.insert(ch);
    }
    dfs(arr, pos+1, curr);
    dfs(arr, pos+1, next);
  }
  int maxLength(vector<string>& arr) {
    dfs(arr, 0, {});
    return ret;
  }
};