class Solution {
public:
    vector<vector<string>> ans;
    void backtrack(int row, int n, vector<string>tmp){

      if(row == n){
        ans.push_back(tmp);
        return;
      }

      for(int i=0; i<n; i++){
        if(is_valid(tmp, row, i)){
          tmp[row][i] = 'Q';
          backtrack(row+1, n, tmp);
          tmp[row][i] = '.';
        }
      }
    }
  
    bool is_valid(vector<string> &board, int row, int col){
      for(int i=row;i>=0;--i)
          if(board[i][col] == 'Q') return false;
      for(int i=row,j=col;i>=0&&j>=0;--i,--j)
          if(board[i][j] == 'Q') return false;
      for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
          if(board[i][j] == 'Q') return false;
      return true;
    }
  
    vector<vector<string>> solveNQueens(int n) {
      vector<string>start = vector<string>(n, string(n, '.'));
      backtrack(0, n, start);
      return ans;
    }
};