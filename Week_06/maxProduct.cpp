class Solution {
public:
    void swap(int& iMin, int& iMax)
    {
        int temp = iMin;
        iMin = iMax;
        iMax = temp;
    }
    int maxProduct(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 1) return nums[0];
        int iMin = nums[0], iMax = nums[0]; 
        int result = nums[0];
        for(int i = 1; i < size; i++)
        {
            if(nums[i] < 0)
            {
                swap(iMin, iMax);
            }
            iMax = max(iMax * nums[i], nums[i]);
            iMin = min(iMin * nums[i], nums[i]);
            result = max(iMax, result);
        }
        return result;
    }
}; 
