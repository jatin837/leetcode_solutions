class Solution {
public:
    bool dfs(int pos, vector<int>&piles, int alice, int bob){
      if(pos == piles.size()/2)
        return alice > bob;
      int first = piles[pos];
      int second = piles[piles.size()-pos-1];
      return dfs(pos+1, piles, alice+first, bob+second)
        || dfs(pos+1, piles, alice+second, bob+first);
    }
    bool stoneGame(vector<int>& piles) {
      return dfs(0, piles, 0, 0);
    }
};