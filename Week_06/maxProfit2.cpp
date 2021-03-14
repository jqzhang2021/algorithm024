class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int size  = (int)prices.size();
        for(int i = 1; i < size; i++)
        {
            int delta = prices[i] - prices[i - 1];
            if(delta > 0)
            {
                result += delta;
            }
        }
        return result;
    }
};
