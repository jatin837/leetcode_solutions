class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int>frq;
      for(char ch:s)
        frq[ch]++;
      int ans = 0;
      for(auto it=frq.begin(); it != frq.end(); it++){
        ans += (it->second/2)*2;
        if(ans%2==0 and it->second%2==1)
          ans += 1;
      }
      return ans;
    }
};