class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }
        vector<int> dp(size, 0);
        dp[0] = 1;
        int result = 1;
        for(int i = 1; i < size; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

