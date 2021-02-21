class Solution {
public:
    void generate(int level, vector<vector<int>>& result, vector<int>& nums, vector<int>& temp)
    {
        if(level >= nums.size())
        {
            result.push_back(temp);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(std::find(temp.begin(), temp.end(), nums[i]) == temp.end())
            {
                temp.push_back(nums[i]);
                generate(level + 1, result, nums, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> result;
        if(nums.size() == 0)
        {
            return result;
        }
        vector<int> temp;
        generate(0, result, nums, temp);
        return result;
    }
};
