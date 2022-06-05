class Solution {
public:
  int ans=0;
  int totalNQueens(int n) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    solve(board, 0);
    return ans;
  }
  bool check(vector<vector<bool>>& board, int row, int col) {
    int n = size(board);
    for(int i = 0; i <= row; i++) {
      if(board[i][col]) return false;
      if(row - i >= 0 && col - i >= 0 && board[row - i][col - i]) return false;
      if(row - i >= 0 && col + i <  n && board[row - i][col + i]) return false;
    }
    return true;
  }    
  void solve(vector<vector<bool>>& board, int row) {
    if(row == size(board)){
      ans++; 
      return;
    }
    for(int col = 0; col < size(board); col++){
      if(check(board, row, col)){
        board[row][col] = true;
        solve(board, row + 1);
        board[row][col] = false;
      }                                
    }
  }
};