class Solution {
public:
  int maxProfit(vector<int>& prices) {
    vector<int>left(prices.size(), 0);
    vector<int>right(prices.size(), 0);
    int minSoFar = prices[0];
    int maxSoFar = prices.back();
    for(int i=1; i<left.size(); i++){
      minSoFar = min(prices[i], minSoFar);
      left[i] = max(left[i-1], prices[i]-minSoFar);
    }
    for(int i=prices.size()-2; i>=0; i--){
      maxSoFar = max(prices[i], maxSoFar);
      right[i] = max(right[i+1], maxSoFar-prices[i]);
    }
    int ret = 0;
    for(int i=0; i<prices.size(); i++)
      ret = max(ret, right[i]+left[i]);
    return ret;
  }
};
