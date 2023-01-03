class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
      int ret = 0;
      for(int c = 0; c<strs[0].size(); c++){
        for(int r = 1; r<strs.size(); r++){
          if(strs[r][c] < strs[r-1][c]){
            ret++;
            break;
          }
        }
      }
      return ret; 
    }
};