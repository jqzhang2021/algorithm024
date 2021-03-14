class Solution {
public:
    int robRange(vector<int>& nums, int start, int end)
    {
        int per = 0, cur = 0, temp = 0;
        for(int i = start; i < end; i++)
        {
            temp = cur;
            cur = max(per + nums[i], cur);
            per = temp;
        }
        return cur;
    }

    int rob(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        return max(robRange(nums, 0, size - 1), robRange(nums, 1, size));
    }
};
