class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int len = gas.size();
      int sum = 0;
      
      int tot = 0;
      int ans = 0;
      for(int i=0; i<len; i++){
        int diff = gas[i]-cost[i];
        sum += diff;
        if(tot + diff < 0){
          tot = 0;
          ans = (i+1)%len;
        }
        else{
         tot+= diff;
        }
      }
      if(sum < 0)
        return -1;
      return ans;
    }
};