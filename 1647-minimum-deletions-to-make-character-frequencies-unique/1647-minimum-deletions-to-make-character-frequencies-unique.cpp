class Solution {
public:
    int minDeletions(string s) {
      vector<int> chfq(26, 0);
      for(char ch:s)
        chfq[ch - 'a']++;
      int ans = 0;
      unordered_set<int>f_count;
      for(int i=0; i<26; i++){
        while(chfq[i] and f_count.count(chfq[i])){
          chfq[i]--;
          ans++;
        }
        f_count.insert(chfq[i]--);
      }
      return ans;
    }
};