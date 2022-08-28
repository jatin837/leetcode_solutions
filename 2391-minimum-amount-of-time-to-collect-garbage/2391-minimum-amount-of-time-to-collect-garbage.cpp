class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
      int t=0;
      int ret = 0;
      unordered_map<char, int>last;
      vector<int>pre(travel.size()+1, 0);
      for(int i=1; i<=travel.size(); i++)
        pre[i] = travel[i-1] + pre[i-1];
      for(int i=0; i<garbage.size(); i++){
        t += garbage[i].length();
        for(char ch:garbage[i])
          last[ch]=i;
      }
      t += pre[last['P']];
      t += pre[last['M']];
      t += pre[last['G']];
      return t;
    }
};