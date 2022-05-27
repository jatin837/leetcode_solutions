class Solution {
public:
    vector<string>ans;
    void backtrack(vector<char> &S, int l=0, int r=0, int n=0){
      if (S.size() == 2*n){
        ans.push_back(string(S.begin(), S.end()));
        return;
      }
      if (l<n){
        S.push_back('(');
        backtrack(S, l+1, r, n);
        S.pop_back();
      }
      if(r < l){
        S.push_back(')');
        backtrack(S, l, r+1, n);
        S.pop_back();
      }
      return;
    }
    vector<string> generateParenthesis(int n) {
      vector<char>tmp; 
      backtrack(tmp, 0, 0, n);
      return ans;
    }
};