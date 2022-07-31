class Solution {
public:
    int minSwap(vector<int>& n1, vector<int>& n2) {
      vector<int>swp(n1.size(), INT_MAX), nswp(n1.size(), INT_MAX);
      swp[0]=1;
      nswp[0]=0;
      for(int i=1; i<n1.size(); i++){
        if(n1[i] > n1[i-1] and n2[i] > n2[i-1]){
          nswp[i] = nswp[i-1];
          swp[i] = swp[i-1] + 1;
        }
        if(n1[i] > n2[i-1] and n2[i] > n1[i-1]){
          swp[i] = min(swp[i], nswp[i-1]+1);    
          nswp[i] = min(nswp[i], swp[i-1]);    
        }
      }
      return min(swp.back(), nswp.back());
    }
};