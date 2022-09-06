class Solution {
public:
    int maxProduct(vector<string>& words) {
      vector<int>cache(words.size());
      int ans = 0;
      for(int i=0; i<words.size(); i++){
        for(char ch:words[i])
          cache[i] |= 1<<(ch-'a');
        for(int j=0; j<i; j++)
          if((cache[i]&cache[j])==0)
            ans = max(ans, int(words[i].length()*words[j].length()));
      }
      return ans;
    }
};