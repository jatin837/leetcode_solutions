class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& props) {
      sort(props.begin(), props.end(), [&](vector<int>& l, vector<int>& r){
        if(l[0] == r[0])
          return l[1] > r[1];
        return l[0] < r[0];
      });
      int cnt = 0;
      int curr = INT_MIN;
      for(int i=props.size()-1; i>=0; i--){
        if(props[i][1]<curr)
          cnt++;
        curr = max(curr, props[i][1]);
      }
      return cnt;
    }
};