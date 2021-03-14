class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        vector<int> dp(size + 1); //比数组长度多1
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < size; i++)
        {
            //DP方程：当前值 = max(前一个值不加nums值，前间隔值加上nums值)
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[size];
    }
};
