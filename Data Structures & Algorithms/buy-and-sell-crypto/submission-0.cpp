class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int maximum_profit = 0;
        int minimum = prices[0];
        for(int i = 0; i< prices.size(); i++){
            if(prices[i]<minimum){
                minimum = prices[i];
            }
            else{
                maximum_profit = max(maximum_profit, prices[i] - minimum);
            }
        }
        return maximum_profit;

        
    }
};