class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int ans = 0;
      if(flowerbed.size() == 1){
        if(flowerbed[0] == 0)
          return n<=1;
        return n==0;
      }
      if(flowerbed[0] == 0 and flowerbed[1] == 0){
        flowerbed[0] = 1; 
        ans++;
      }
      for(int i=1; i<flowerbed.size()-1; i++)
        if(flowerbed[i-1] == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0){
          flowerbed[i] = 1;
          ans++;
      }
      if(flowerbed[flowerbed.size()-1] == 0 and flowerbed[flowerbed.size()-2] == 0){
        flowerbed[1] = 1; 
        ans++;
      }
      return ans>=n;
    }
};