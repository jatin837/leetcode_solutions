class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int len = nums.size();
      sort(nums.begin(), nums.end());
      
      vector<vector<int>> ans;
      
      int l = 1;
      int h = len-1;
      
      if(len==3 and nums[0] + nums[1] + nums[2] == 0)
        return {nums};
      
      while(l<h){
        if(nums[0] + nums[l] + nums[h] == 0){
          ans.push_back({nums[0], nums[l], nums[h]});
          h--;
          while(l<h and nums[h] == nums[h+1])
            h--;
        }else if(nums[l] + nums[h] > -1*nums[0])
          h--;
        else
          l++;
      }
      
      for(int i=1; i<len-1; i++){
        int l = i+1, h = len-1;
        if(nums[i] != nums[i-1]){
          while(l<h){
            if(nums[l] + nums[h] == -1*nums[i]){
              ans.push_back({nums[i], nums[l++], nums[h--]});
              while(l < h and nums[h] == nums[h+1])
                h--;
            }
            else if(nums[l] + nums[h] > -1*nums[i]){
              h--;
            }
            else
              l++;
          }
          cout<<i<<'\n';
        }
      }
      
      return ans;
    }
};