class Solution {
public:
    static bool cmp(string& s1, string& s2){
      return s1.length()<s2.length();
    }
    bool isPred(string &w1, string &w2){
      if(w1.length() != w2.length()-1)
        return false;
      int p1=0;
      int p2=0;
      
      while(p1<w1.length() and p2<w2.length()){
        if(w1[p1] == w2[p2]){
          p1++;
          p2++;
        }
        else
          p2++;
        if(p2-p1 == 2)
          return false;
      }
      return true;
    }
  
//  int longestStrChain(vector<string>& words) {
//    vector<int>dp(words.size(), 1);
//    sort(begin(words), end(words), cmp);
//    dp[0] = 1;
//    for(int i=1; i<dp.size(); i++){
//      for(int j=0; j<i; j++){
//        if(isPred(words[j], words[i]))
//          dp[i] = max(dp[i], 1+dp[j]);
//      }
//    }
//    return *max_element(begin(dp), end(dp)); 
//  }
  int longestStrChain(vector<string>& words) {
    vector<int>dp(words.size(), 1);
    sort(begin(words), end(words), cmp);
    dp[0] = 1;
    unordered_map<int, vector<int>>pred;
   
    pred[words[0].length()].push_back(0);
    int ans = 1;
    for(int i=1; i<dp.size(); i++){
      for(auto idx:pred[words[i].length()-1])
        if(isPred(words[idx], words[i]))
          dp[i] = max(dp[i], 1+dp[idx]);
      pred[words[i].length()].push_back(i);
      ans = max(dp[i], ans);
    }
    return ans; 
  }
};