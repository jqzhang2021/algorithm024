class Solution {
public:
    int getCount(int value, vector<int>& nums, int low, int high)
    {
        int result = 0;
        for (int i = low; i <= high; i++)
        {
            if (nums[i] == value)
            {
                result += 1;
            }
        }
        return result;
    }

    int recursion(vector<int>& nums, int low, int high)
    {
        if (low == high)
        {
            return nums[low];
        }
        int middle = (low + high) / 2;
        int left = recursion(nums, low, middle);
        int right = recursion(nums, middle + 1, high);
        if (left == right)
        {
            return left;
        }
        int leftCount = getCount(left, nums, low, high);
        int rightCount = getCount(right, nums, low, high);
        if (leftCount >= rightCount)
        {
            return left;
        }
        return right;
    }

    int majorityElement(vector<int>& nums) 
    {
        return recursion(nums, 0, nums.size() - 1);
    }
};
