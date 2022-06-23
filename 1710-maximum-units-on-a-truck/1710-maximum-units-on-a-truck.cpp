class Solution {
public:
    static bool cmp(vector<int>&l, vector<int>&r){
      return l[1] > r[1]; 
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(), boxTypes.end(), cmp);
      int tot = 0;
      int box = 0;
      for(auto boxType:boxTypes){
        if(box == truckSize)
          return tot;
        if(box+boxType[0] <= truckSize){
          tot += boxType[0]*boxType[1];
          box += boxType[0];
        }else{
          tot += (truckSize-box)*boxType[1];
          box += truckSize-box;
        }
      }
      return tot;
    }
};