class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      for(int i=0; i<mat[0].size(); i++){
        int r = 0, c = i;
        vector<int>tmp;
        while(r<mat.size() && c<mat[0].size())
          tmp.push_back(mat[r++][c++]);
        sort(tmp.begin(), tmp.end());
        r = 0, c=i;
        for(int i=0; i<tmp.size(); i++)
          mat[r++][c++]=tmp[i];
      }
      for(int i=1; i<mat.size(); i++){
        int r = i, c = 0;
        vector<int>tmp;
        while(r<mat.size() && c<mat[0].size())
          tmp.push_back(mat[r++][c++]);
        sort(tmp.begin(), tmp.end());
        r=i, c=0;
        for(int i=0; i<tmp.size(); i++)
          mat[r++][c++]=tmp[i];
      }
      return mat;
    }
};