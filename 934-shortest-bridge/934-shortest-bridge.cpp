class Solution {
public:
  void paint(vector<vector<int>>& A, int i, int j) {
    if (i<0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] == 2 || A[i][j] == 0)
      return;
    A[i][j] = 2;
    paint(A, i-1, j);
    paint(A, i+1, j);
    paint(A, i, j+1);
    paint(A, i, j-1);
  }
  bool expand(vector<vector<int>>& A, int i, int j, int colr) {
    if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size())
      return false;
    if(!A[i][j])
      A[i][j] = colr+1;
    return A[i][j] == 1;
  }
  int shortestBridge(vector<vector<int>>& A) {
    bool found = false;
    for(int i=0; !found && i<A.size(); i++){
      for(int j=0; !found && j<A[0].size(); j++){
        if(A[i][j]){
          paint(A, i, j);
          found = true;
        }
      }
    }
    for (int cl = 2; ; ++cl)
      for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j) 
          if (A[i][j] == cl && ((expand(A, i - 1, j, cl) || expand(A, i, j - 1, cl) || 
            expand(A, i + 1, j, cl) || expand(A, i, j + 1, cl))))
              return cl - 2;
  }
};