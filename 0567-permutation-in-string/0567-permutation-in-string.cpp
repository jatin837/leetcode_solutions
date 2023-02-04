class Solution {
public:
  bool areEqual(int mp1[], int mp2[]){
    for(int i=0; i<26; i++)
      if(mp1[i] != mp2[i])
        return false;
    return true;
  }
  bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length())
      return false;
    int mp1[26] = {0}, mp2[26]={0};
    int len = s1.size();
    for(int i=0; i<len; i++){
      char ch1 = s1[i], ch2 = s2[i];
      mp1[ch1-'a']++;
      mp2[ch2-'a']++;
    }
    int beg = 0;
    int end = len-1;
    while(end < s2.size()){
      for(int i=0; i<len; i++)
        if(areEqual(mp1, mp2))
          return true;
      mp2[s2[beg]-'a']--;
      beg++;
      end++;
      if(end < s2.size())
        mp2[s2[end]-'a']++;
    }
    return false;
  }
};