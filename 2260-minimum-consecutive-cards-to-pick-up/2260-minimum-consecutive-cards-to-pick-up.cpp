class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
      unordered_map<int, int>mp;
      int right = 0;
      int ret = INT_MAX;
      while(right < cards.size()){
        int currCard = cards[right];
        int left = mp[currCard]-1;
        mp[currCard] = right+1;
        right++;
        if(left == -1)
          continue;
        ret = min(ret, right-left);
      }
      return ret==INT_MAX?-1:ret;
    }
};