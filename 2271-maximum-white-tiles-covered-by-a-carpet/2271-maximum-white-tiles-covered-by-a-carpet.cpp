//class Solution {
//public:
//    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
//        sort(tiles.begin(),tiles.end());
//        int n=tiles.size(),s=0,e=0,ans=0,area=0;
//        while(s<n and e<n){
//            if(tiles[e][1]-tiles[s][0]>len){
//                area+=tiles[e][1]-tiles[e][0]+1;
//                ans=max(ans,area);   
//                ++e;
//            }
//            else{
//                ans=max(ans,area+max(0,tiles[s][0]+len-tiles[e][0]));
//                area-=(tiles[s][1]-tiles[s][0]+1);
//                ++s;
//            }
//        }
//        return ans;        
//    }
//};



class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        sort(tiles.begin(),tiles.end());
        int n=tiles.size(),s=0,e=0,ans=0,area=0;
        for(;e<n && s<n;){
            if(tiles[e][1] - tiles[s][0] < len){
                area+=tiles[e][1]-tiles[e][0]+1;
                ans=max(ans,area);   
                ++e;
            }
            else{
                ans=max(ans,area+max(0,tiles[s][0]+len-tiles[e][0]));
                area-=(tiles[s][1]-tiles[s][0]+1);
                ++s;
            }
        }
        return ans;        
    }
};