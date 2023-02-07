class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    if(fruits.size() == 1)
      return 1;
    int left = 0;
    int right = 1;
    unordered_map<int, int>mp;
    mp[fruits[0]]++;
    mp[fruits[1]]++;
    int ret = 0;
    while(left < right && right < fruits.size()){
      if(mp.size() > 2){
        mp[fruits[left]]--;
        if(mp[fruits[left]] == 0)
          mp.erase(fruits[left]);
        left++;
        continue;
      }
      ret = max(ret, right-left+1);
      right++;
      if(right == fruits.size())
        continue;
      mp[fruits[right]]++;

    }
    return ret;
  }
};