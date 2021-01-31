#include <vector>

#using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
       if(nums.size() <= 1)
       {
           return nums.size();
       }
       int index = 0; //双“指针”中指向当前不重复元素的下标值
       for(int i = 1; i < nums.size(); i++)
       {
           if(nums[i] != nums[index])
           {
               index += 1;
               nums[index] = nums[i]; //将不重复的值存入不重复值的索引中
           }
       }
       return index + 1;
    }
};
