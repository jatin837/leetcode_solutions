class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_pro=0;
        int min_buy=INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            min_buy= min(min_buy, prices[i]);
            max_pro= max(max_pro, prices[i]-min_buy);
        }
     
       return max_pro; 
    }
};