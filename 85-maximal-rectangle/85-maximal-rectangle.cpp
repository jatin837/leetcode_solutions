class Solution {
public:
  int func(vector<int>& heights) {
    vector<int>L(heights.size(), -1), R(heights.size(), heights.size());
    stack<int>st1, st2;
    for(int i=heights.size()-1; i>=0; i--){
      while(!st1.empty() && heights[i] < heights[st1.top()]){
        L[st1.top()] = i;
        st1.pop();
      }
      st1.push(i);
    }
    for(int i=0; i<heights.size(); i++){
      while(!st2.empty() && heights[i] < heights[st2.top()]){
        R[st2.top()] = i;
        st2.pop();
      }
      st2.push(i);
    }
    int ret = 0;
    for(int i=0; i<heights.size(); i++)
      ret = max(ret, ((R[i]-L[i])-1)*heights[i]);
    return ret;
  }
  int maximalRectangle(vector<vector<char>>& matrix) {
    int ret = 0;
    vector<int>dp(matrix[0].size(), 0);
    for(int i=0; i<matrix.size(); i++){
      for(int j=0; j<matrix[0].size(); j++){
        if(matrix[i][j] == '1')
          dp[j] += 1; 
        else
          dp[j] = 0;
      }
      ret = max(func(dp), ret);
    }
    return ret;
  }
};