class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int profit = 0, minprice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                profit = max(profit, prices[i] - minprice);
                else 
                minprice = min(minprice, prices[i]);
        }
        return profit;
    }
};