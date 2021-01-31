#include <vector>

using std::vector;

// 双指针法：
// 1）将前指针遇到的非零数字依后指针摆放在数组内。
// 2）将后指针只有的数组元素设置为0

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] != 0)
            {
                nums[i++] = nums[j];
            }
        }
        
        for(int k = i; k < nums.size(); k++)
        {
            nums[k] = 0;
        }
        
    }
};
