class Solution {
public:
    //compute the prefix along row
    void prefix(vector<vector<int>>&M){
      int r = M.size(), c = M[0].size();
      for(int i=1; i<r; i++)
        for(int j=0; j<c; j++)
          M[i][j] += M[i-1][j];     
    }
    //compress matrix vertically
    vector<int> compress(vector<vector<int>>&M, int r2, int r1){
      vector<int>v(M[0].size());
      for(int i=0; i<M[0].size(); i++)
        v[i] = (r1==0)?M[r2][i]:M[r2][i]-M[r1-1][i];
      return v;
    }
    // main algorithm
    int solve(vector<int>v, int k){
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
    int maxSumSubmatrix(vector<vector<int>>& M, int k) {
      int r = M.size(), c = M[0].size();
      prefix(M);
      int ans = INT_MIN;
      for(int i=0; i<r; i++){
        for(int j=0; j<=i; j++){
          vector<int>compressed = compress(M, i, j);
          ans = max(ans, solve(compressed, k));
          if(ans == k)
            return k;
        }
      }
      return ans;
    }
};

/*
Whatever you thought was incorrect.
Initially I Thought I'd be able to do it in linear time.
But, The approach that I thought about was only valid for target sum only.
Here, It's similar to maximum subarray problem(kadan's algorithm), along with some additional condition that sum has to be less than or equal to K
*/