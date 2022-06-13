class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
       if(n==1){
          return triangle[0][0];
       }
       for(int i = 1 ; i < n ; i++)
         for(int j = 0 ; j < i+1; j++)
           triangle[i][j] +=  min((j<i?triangle[i-1][j]:1e8),(j>0?triangle[i-1][j-1]:1e8));
       return *min_element(triangle[n-1].begin(), triangle[n-1].end());
  }
};