class Solution {
public:
  vector<int>getOverlap(vector<int>&p1, vector<int>&p2){
    return {max(p1[0], p2[0]), min(p1[1], p2[1])};
  }
  int findMinArrowShots(vector<vector<int>>& p) {
    sort(p.begin(), p.end());
    stack<vector<int>>st;
    st.push(p[0]);
    for(int i=1; i<p.size(); i++){
      vector<int> overlap = getOverlap(st.top(), p[i]);
      if(overlap[0] <= overlap[1])
        st.pop();
      else
        overlap = p[i];
      st.push(overlap);
    }
    return st.size();
  }
};
