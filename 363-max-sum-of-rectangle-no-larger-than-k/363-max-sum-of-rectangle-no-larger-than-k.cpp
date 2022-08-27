class Solution {
public:
    void prefix(vector<vector<int>>&M){
      int r = M.size(), c = M[0].size();
      for(int i=1; i<r; i++)
        for(int j=0; j<c; j++)
          M[i][j] += M[i-1][j];     
    }
    vector<int> compress(vector<vector<int>>&M, int r2, int r1){
      vector<int>v(M[0].size());
      for(int i=0; i<M[0].size(); i++)
        v[i] = (r1==0)?M[r2][i]:M[r2][i]-M[r1-1][i];
      return v;
    }
    int solve(vector<vector<int>>&M, int i, int j, int k){
      vector<int>v = compress(M, i, j);
      set<int>st;
      st.insert(0);
      int sum = 0;
      int ret = INT_MIN;
      for(int i=0; i<v.size(); i++){
        sum += v[i];
        if(sum == k)
          return k;
        auto indx = st.lower_bound(sum-k);
        if(indx != st.end())
          ret = max(ret, sum - *indx);
        st.insert(sum);
      }
      return ret;
    }
    int maxSumSubmatrix(vector<vector<int>>&M, int k) {
      prefix(M);
      int ans = INT_MIN;
      for(int i=0; i<M.size(); i++)
        for(int j=0; j<=i; j++)
          if(ans == k)
            return ans;
          else
            ans = max(ans, solve(M, i, j, k));
      return ans;
    }
};