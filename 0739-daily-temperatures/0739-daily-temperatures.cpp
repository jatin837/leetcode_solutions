class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
      vector<int>ret(temps.size(), temps.size());
      stack<int>monoSt;
      for(int i=0; i<temps.size(); i++){
        while(monoSt.size() && temps[monoSt.top()] < temps[i]){
          ret[monoSt.top()] = i;
          monoSt.pop();
        }
        monoSt.push(i);
      }
      for(int i=0; i<ret.size(); i++){
        if(ret[i] != temps.size())
          ret[i] -= i;
        else
          ret[i] = 0;
      }
      return ret;
    }
};