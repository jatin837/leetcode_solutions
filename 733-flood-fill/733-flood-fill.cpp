class Solution {
public:
    bool visited[50][50] = {false};
    void dfs(vector<vector<int>>&img, int r, int c, int t, int col){
      if(r<0 or r>=img.size() or c < 0 or c >=img[0].size() or img[r][c] != t or visited[r][c])
        return;
      img[r][c] = col;
      visited[r][c] = true;
      dfs(img, r-1, c, t, col);
      dfs(img, r+1, c, t, col);
      dfs(img, r, c-1, t, col);
      dfs(img, r, c+1, t, col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int ic = image[sr][sc]; 
      dfs(image, sr, sc, ic, color);
      return image;
    }
};