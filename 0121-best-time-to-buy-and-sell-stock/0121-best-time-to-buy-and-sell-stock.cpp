class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;
        for(int i=0; i<prices.size(); i++){
            profit = max(profit, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};