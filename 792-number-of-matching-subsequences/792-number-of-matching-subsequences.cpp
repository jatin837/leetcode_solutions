class Solution {
public:
    bool isSubSeq(string s1, string s2){
      int i=0, j=0;
      while(i < s1.size() and j < s2.size()){
        if(s1[i] == s2[j]){ i++;j++;  }
        else{i++;}
      }
      return j==s2.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
      unordered_map<string, int>mp;
      int cnt = 0;
      for(string word:words)
        mp[word]++; 
      for(auto it=mp.begin(); it!=mp.end(); it++){
        if(isSubSeq(s, it->first))
          cnt += it->second;
      }
      return cnt;
    }
};