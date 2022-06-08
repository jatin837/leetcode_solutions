class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int len = gas.size();
      int sum = 0;
      int curr_sum = 0;
      int ans = 0;
      for(int i=0; i<len; i++){
        int diff = gas[i]-cost[i];
        sum += diff;
        if(curr_sum + diff < 0){
          curr_sum = 0;
          ans = (i+1)%len;
        }
        else
         curr_sum+= diff;
      }
      if(sum < 0)
        return -1;
      return ans;
    }
};