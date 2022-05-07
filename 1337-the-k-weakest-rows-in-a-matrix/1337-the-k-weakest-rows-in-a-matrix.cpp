class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      int N = mat.size();
      vector<pair<int, int>> idx_sold; 
      int i = 0;
      for(auto row:mat)
        idx_sold.push_back(make_pair(i++, accumulate(row.begin(), row.end(), 0)));
      

    //for(auto p:idx_sold){
    //  cout<<p.first<<' '<<p.second<<'\n';
    //}
      
      sort(
        idx_sold.begin(),
        idx_sold.end(),
        [](const auto& lhs, const auto& rhs) {
        if(lhs.second != rhs.second)
          return lhs.second < rhs.second;
        else
          return lhs.first < rhs.first;
      });
      
      for(auto p:idx_sold){
        cout<<p.first<<' '<<p.second<<'\n';
      }
      vector<int>ans;
      for(int i=0; i<k; i++){
        ans.push_back(idx_sold[i].first);
      }
      return ans;
    }
};