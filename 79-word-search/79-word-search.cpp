class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int n = board.size();
      int m = board[0].size();
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if (exist(0, board, word, i, j))
            return true;
        }
      }
      return false;
    }
    bool exist(int idx,
               vector<vector<char>>& board,
               string& word,
               int x,
               int y
              ){
      if (idx == word.length())
        return true;
      if(x < 0 or y < 0 or x == board.size() or y == board[0].size())
        return false;
      if (word[idx] != board[x][y])
        return false;
      char tmp = board[x][y];
      board[x][y] = ' ';
      bool res = 
        exist(idx+1, board, word, x+1, y) or
        exist(idx+1, board, word, x-1, y) or
        exist(idx+1, board, word, x, y+1) or
        exist(idx+1, board, word, x, y-1);
      board[x][y] = tmp;
      return res;
    }
};