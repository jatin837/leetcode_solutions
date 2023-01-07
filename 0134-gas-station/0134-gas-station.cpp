class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int start = 0;
      int curr = 0;
      int tot = 0;
      int i=0;
      while(i < gas.size()){
        tot += gas[i]-cost[i];
        curr += gas[i]-cost[i];
        if(curr < 0){
          curr = 0;
          start = i+1;
        }
        i++;
      }
      if(tot < 0)
        return -1;
      return start;
    }
};