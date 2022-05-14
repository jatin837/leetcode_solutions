class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows == 1)
        return s;
      
      vector<string> rows(min(numRows, int(s.size())));
      int curr_row = 0;
      bool going_down = false;
      
      for(char ch:s){
        rows[curr_row] += ch;
        if(curr_row == 0 || curr_row == numRows-1)
          going_down = !going_down;
        curr_row += going_down ? 1:-1;
      }
      string ret;
      for(auto row:rows)
        ret += row;
      return ret;
    }
};


/*
create a vector of strings
*/