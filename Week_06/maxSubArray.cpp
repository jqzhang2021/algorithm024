class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int size = nums.size();
        int result = nums[0];
        int cache = nums[0];
        for(int i = 1; i < size; i++)
        {
            if(cache < 0)
            {
                cache = nums[i];
            }
            else
            {
                cache += nums[i];
            }
            if(result < cache)
            {
                result = cache;
            }
        }
        return result;
    }
};
