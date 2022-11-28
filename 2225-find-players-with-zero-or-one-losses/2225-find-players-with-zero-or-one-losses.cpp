class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>played, won;
        for(auto match:matches){
            int winner = match[0];
            int looser = match[1];
            played[winner]++;
            played[looser]++;
            won[winner]++;
        }
        vector<vector<int>>ret(2);
        for(auto [player,playCnt]:played){
            if(playCnt == won[player])
                ret[0].push_back(player);
            else if(playCnt == 1+won[player])
                ret[1].push_back(player);
        }
        sort(ret[0].begin(), ret[0].end());
        sort(ret[1].begin(), ret[1].end());
        return ret;
    }
};