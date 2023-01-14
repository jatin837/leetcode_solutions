class Solution {
public:
  int find(int repr[], int indx){
    if(repr[indx] == indx)
      return indx;
    return find(repr, repr[indx]);
  }
  void unite(int repr[], int i, int j){
    int a = find(repr, i);
    int b = find(repr, j);
    if(a < b)
      repr[b] = a;
    else
      repr[a] = b;
  }
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int repr[26];
    for(int i=0; i<26; i++)
      repr[i] = i;
    for(int i=0; i<s1.size(); i++){
//    for(int i=0; i<26; i++)
//      printf("(%d,%d), ", i, repr[i]);
//    cout<<'\n';
      char ch1 = s1[i], ch2 = s2[i];
      unite(repr, ch1-'a', ch2-'a');
    }
    for(int i=0; i<baseStr.size(); i++){
      char ch = baseStr[i]; 
      baseStr[i] = char('a' + find(repr, ch-'a'));
//      cout<<i<<'\n';
    }
    return baseStr;
  }
};