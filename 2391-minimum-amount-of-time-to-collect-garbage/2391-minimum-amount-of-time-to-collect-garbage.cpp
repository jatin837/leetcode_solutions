class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
      int t=0;
      int ret = 0;
      int last[3]={0};
      string type = "PGM";
      vector<int>pre(travel.size()+1, 0);
      for(int i=1; i<=travel.size(); i++)
        pre[i] = travel[i-1] + pre[i-1];
      for(int i=0; i<garbage.size(); i++){
        t += garbage[i].length();
        for(char ch:garbage[i])
          for(int j=0; j<3; j++)
            if(type[j] == ch)
              last[j]=i;
      }
      t += pre[last[0]]+pre[last[1]]+pre[last[2]];
      return t;
    }
};