class Solution {
public:
    vector<pair<int, int>> dd = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int color) {
        stack<pair<int, int>>stp;
        int init = image[x][y];
        if(image[x][y] == color)
            return image;
        stp.push({x,y});
        while(!stp.empty()){
            auto [x, y] = stp.top();
            stp.pop();
            if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size() || image[x][y] != init)
                continue;
            image[x][y] = color;
            stp.push({x+1, y});
            stp.push({x-1, y});
            stp.push({x, y+1});
            stp.push({x, y-1});
        }
        return image;
    }
    
};