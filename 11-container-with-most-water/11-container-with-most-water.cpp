class Solution {
public:
    int maxArea(vector<int>& height) {
      int len = height.size();
      int ans = 0;
      
      int l=0;
      int r=len-1;
      while(l!=r){
        ans = max(ans, (r-l)*min(height[l], height[r]));
        if(height[l] > height[r])
          r--;
        else
          l++;
      }

      return ans;
    }
};