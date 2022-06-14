class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int n = prices.size();
        int max_sell  = prices[n-1];//4
        for(int i=n-2;i>=0;i--){
            if(prices[i]<max_sell){
                
                max_profit = max(max_profit,max_sell-prices[i]);//1
                
            }
            max_sell = max(max_sell,prices[i]);
        }
        return max_profit;
    }
};