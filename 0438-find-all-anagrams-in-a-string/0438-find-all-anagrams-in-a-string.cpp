class Solution {
public:
    bool areAnagrams(int a[], int b[]){
      for(int i=0; i<26; i++)
        if(a[i] != b[i])
          return false;
      return true;
    }
    vector<int> findAnagrams(string s, string p) {
      int smp[26] = {0};
      int pmp[26] = {0};
      if(s.length() < p.length())
        return {};
      for(int i=0; i<p.length(); i++)
        smp[s[i]-'a']++;
      for(int i=0; i<p.length(); i++)
        pmp[p[i]-'a']++;
      vector<int>ret;
      int start = 0;
      while(start <= s.length() - p.length()){
        if(areAnagrams(smp, pmp))
          ret.push_back(start);
        smp[s[start]-'a']--;
        if(start + p.length() < s.length())
          smp[s[start + p.length()] - 'a']++;
        start++;
      }
      return ret;
    }
};