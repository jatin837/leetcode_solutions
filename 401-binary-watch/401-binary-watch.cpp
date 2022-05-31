class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
      vector<string> ans;
      for(int i=0; i<12; i++){
        for(int j=0; j<60; j++){
         if(__builtin_popcount(i)+__builtin_popcount(j) ==  turnedOn){
           
          if(j < 10)
            ans.push_back(to_string(i) + ":0" + to_string(j));
          else
            ans.push_back(to_string(i) + ":" + to_string(j));
         }
        }     
      }
      return ans;  
    }
};