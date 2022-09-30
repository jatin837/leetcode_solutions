class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>>pts;
    vector<vector<int>>ret;
    multiset<int>active;
    active.insert(0);
    for(int i=0; i<buildings.size(); i++)
      pts.push_back({buildings[i][0],-buildings[i][2]}), 
                     pts.push_back({buildings[i][1], buildings[i][2]});

    sort(pts.begin(), pts.end());
    int prev = 0;
    int curr = 0;
    for(auto pt:pts){
      if(pt[1]>0)
        active.erase(active.find(pt[1]));
      else
        active.insert(-pt[1]);
      curr = *active.rbegin();
      if(curr != prev){
        ret.push_back({pt[0], curr});
        prev = curr;
      }
    }
    return ret;
  }
};