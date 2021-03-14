class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        if(size < 2) return 0;
        int income = 0; // 收益
        int lowestPrice = prices[0]; //最低价格
        for(int i = 1; i < size; i++)
        {
            income = max(prices[i] - lowestPrice, income);
            lowestPrice = min(prices[i], lowestPrice);
        }
        return income;
    }
};
