class Solution {
public:
  bool reorderedPowerOf2(int N) {
    vector<vector<int>>solSpace(30, vector<int>(10, 0));
    unsigned long n = 1;
    for(int i=0; i<30; i++){
      unsigned long num = 1<<i;
      while(num){
        solSpace[i][num%10]++; 
        num/=10;
      }
    }
    vector<int>given(10);
    while(N){
      given[N%10]++;
      N/=10;
    }
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