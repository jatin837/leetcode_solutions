class Solution {
public:
  bool isPalindrome(string& s, int i, int j){
    if(i==j or j<i)
      return true;
    return s[i] == s[j] && isPalindrome(s, i+1, j-1);
  }
  vector<vector<string>> partition(string s) {
    unordered_map<int, vector<vector<string>>>dp;
    dp[0].push_back({s.substr(0, 1)});
    for(int i=1; i<s.length(); i++){
      for(int k=i; k>=0; k--)
        if(isPalindrome(s, k, i)){
          for(auto vec:dp[k-1]){
            vec.push_back(s.substr(k, i-k+1));
            dp[i].push_back(vec)  ;
          }
        }
      if(isPalindrome(s, 0, i))
        dp[i].push_back({s.substr(0, i+1)});
    }
    return dp[s.length()-1];
  }
};