class Solution {
public:
    int ans = INT_MAX;
    void backtrack(vector<int>&sol, vector<int>&cookies, int start){
      if (start == cookies.size()){
        ans = min(*max_element(begin(sol), end(sol)), ans);
        return;
      }
      for(int j=0; j<sol.size(); j++){
        sol[j] += cookies[start];
        backtrack(sol, cookies, start+1);
        sol[j] -= cookies[start];
      }
    }
    int distributeCookies(vector<int>& cookies, int k) {
      vector<int> sol(k);
      backtrack(sol, cookies, 0);
      return ans;
    }
};