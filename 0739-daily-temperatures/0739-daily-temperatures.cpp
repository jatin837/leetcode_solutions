/*
- This problem wants closest element on the right of the array which is strictly greater than the current index.
- So, ultimilately, this is a Monotonic stack problem
- Basically, we need to build the monotonically decreasing stack while scanning each element in the array
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
      stack<int>monoSt;
      for(int i=0; i<temps.size(); i++){
        while(monoSt.size() && temps[monoSt.top()] < temps[i]){
          temps[monoSt.top()] = i-monoSt.top();
          monoSt.pop();
        }
        monoSt.push(i);
      }
      while(monoSt.size()){
        temps[monoSt.top()] = 0;
        monoSt.pop();
      }
      return temps;
    }
};