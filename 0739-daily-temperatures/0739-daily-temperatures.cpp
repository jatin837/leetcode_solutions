class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
      vector<int>ret(temps.size(), 0);
      stack<int>monoSt;
      for(int i=0; i<temps.size(); i++){
        while(monoSt.size() && temps[monoSt.top()] < temps[i]){
          ret[monoSt.top()] = i-monoSt.top();
          monoSt.pop();
        }
        monoSt.push(i);
      }
      return ret;
    }
};