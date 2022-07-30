class Solution {
public:
    bool isSuperSet(int A[26], int B[26]){
      for(int i=0; i<26; i++){
        if(B[i] > A[i])
          return false;
      }
      return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      int B[26] = {0};
      for(string word:words2){
        int tmp[26]={0};
        for(char ch:word)
          B[ch-'a'] = max(B[ch-'a'], ++tmp[ch-'a']);
      }
      vector<string>ans;
      for(string word:words1){
        int A[26] = {0};
        for(char ch:word)
          A[ch-'a']++;
        if(isSuperSet(A, B))
          ans.push_back(word);
      }
      return ans;
    }
};