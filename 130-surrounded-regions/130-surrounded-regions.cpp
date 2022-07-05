class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
      if(r == -1 or r == board.size() or c == -1 or c == board[0].size() or board[r][c] != 'O')
        return;
      board[r][c] = 'N';
      dfs(board, r+1, c);
      dfs(board, r, c+1);
      dfs(board, r-1, c);
      dfs(board, r, c-1);
    }
    void solve(vector<vector<char>>& board) {
      int rn = board.size();
      int cn = board[0].size();
      for(int i=0; i<cn; i++){
        if(board[0][i] == 'O')
          dfs(board, 0, i);
        if(board[rn-1][i] == 'O')
          dfs(board, rn-1, i);
      }
      for(int i=0; i<rn; i++){
        if(board[i][0] == 'O')
          dfs(board, i, 0);
        if(board[i][cn-1] == 'O')
          dfs(board, i, cn-1);
      }
      for(int i=0; i<rn; i++){
        for(int j=0; j<cn; j++){
          if(board[i][j] == 'O')
            board[i][j] = 'X';
          else if(board[i][j] == 'N')
            board[i][j] = 'O';
        }
      }
    }
};