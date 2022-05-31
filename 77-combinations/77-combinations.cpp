class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int idx, int n, int k, vector<int> tmp){
      if(tmp.size() == k){
        ans.push_back(tmp);
        return;
      }
      for(int i=idx; i<=n; i++){
        tmp.push_back(i);
        backtrack(i+1, n, k, tmp);
        tmp.pop_back();
      }
        
    }
    vector<vector<int>> combine(int n, int k) {
      backtrack(1, n, k, {});
      return ans; 
    }
};