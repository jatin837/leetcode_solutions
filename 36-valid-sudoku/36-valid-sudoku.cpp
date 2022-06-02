class Solution {
public:
    bool isValidUnit(vector<char> unit){
      int n_dots = 0;
      set<char>st;
      for(auto ch:unit){
        st.insert(ch);
        if(ch == '.')
          n_dots++;
      }
      if (9-n_dots == st.size()-1)
        return true;
      return false;
    }
    void getBlock(int i, int j, vector<vector<char>>&board, vector<char>&block){
      for(int k=i;k<i+3;k++)
        for(int l=j;l<j+3;l++)
          block.push_back(board[k][l]);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<char>col;
      vector<char>b1;
      for(int i=0; i<9; i++){
        if(!isValidUnit(board[i]))
          return false;
        for(int j=0; j<9; j++){
          col.push_back(board[j][i]);
        }
        if(!isValidUnit(col))
          return false;
        col.clear();
      }
      for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
          getBlock(3*i, 3*j, board, b1);
          if(!isValidUnit(b1))
            return false;
          b1.clear();
        }
      }
      return true;
    }
};