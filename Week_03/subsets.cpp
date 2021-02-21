class Solution {
public:
    void generate(int level, vector<int>& nums, vector<int>& current, vector<vector<int>>& result)
    {
        if (level == nums.size())
        {
            result.push_back(current);
            return;
        }
        generate(level + 1, nums, current, result);
        current.push_back(nums[level]);
        generate(level + 1, nums, current, result);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> temp;
        temp.reserve(nums.size());
        generate(0, nums, temp, result);
        return result;
    }
};
