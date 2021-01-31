#include <vector>
using std::vector;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end)
    {
        int mid = (start + end) / 2 - start;
        for (int i = 0; i <= mid; i++)
        {
            int temp = nums[start + i];
            nums[start + i] = nums[end - i];
            nums[end - i] = temp;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(nums.size() == 1 || k == 0)
        {
            return;
        }
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
