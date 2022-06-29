// Binary Sdearch
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      sort(potions.begin(), potions.end());
      vector<int>ans;
      int idx = 0;
      for(int num:spells){
        if(success%num)
          idx = upper_bound(potions.begin(), potions.end(), success/num) - potions.begin();
        else
          idx = lower_bound(potions.begin(), potions.end(), success/num) - potions.begin();
        ans.push_back(potions.size()-idx);
      }
      return ans;
    }
};