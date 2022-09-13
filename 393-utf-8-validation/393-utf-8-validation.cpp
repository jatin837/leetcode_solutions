class Solution {
public:
    bool validUtf8(vector<int>& data) {
      int i = 0;
      int cnt = 0;
      while(i<data.size()){
        while(cnt--){
          if(i == data.size() || (data[i]>>6) != 2)
            return false;
          i++;
        }
        cnt = 0;
        if(i == data.size())
          break;
        if((data[i]>>7)==0){
          i++; 
          continue;
        }
        if((data[i]>>5) == 6){
          cnt = 1;
          i++;
          continue;
        }
        if((data[i]>>4) == 14){
          cnt = 2;
          i++;
          continue;
        }
        if((data[i]>>3) == 30){
          cnt = 3;
          i++;
          continue;
        }
        return false;
      }
      return cnt==0;
    }
};