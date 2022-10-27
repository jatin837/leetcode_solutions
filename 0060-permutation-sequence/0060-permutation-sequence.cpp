class Solution {
public:
  string getPermutation(int n, int k) {
    string s="", ans="";
    int i=0;
    for(int i=0; i<n; i++)
      s += to_string(i+1);
    do{
      ans = s;
      i++;
      if(i==k)
        break;
    }while(next_permutation(s.begin(), s.end()));
    return s;
  }
};