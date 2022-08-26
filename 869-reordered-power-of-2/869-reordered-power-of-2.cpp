class Solution {
public:
  vector<int>count(int N){
    vector<int>ret(10, 0);
    while(N){
      ret[N%10]++;
      N/=10;
    }
    return ret;
  }
  bool reorderedPowerOf2(int N) {
    vector<vector<int>>solSpace(30, vector<int>(10, 0));
    vector<int>given(10);
    for(int i=0; i<30; i++)
      solSpace[i] = count(1<<i);
    given = count(N);
    for(int i=0; i<30; i++){
      bool found = true;
      for(int j=0; j<10; j++)
        if(given[j] != solSpace[i][j])
          found = false;
      if(found)
        return true;
    }
    return false;
  }
};