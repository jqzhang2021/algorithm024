class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> temp;
        for(auto i = 0; i < nums.size(); i++)
        {
            int v = target - nums.at(i);
            if(temp.find(v) != temp.end())
            {
                return vector<int>{i, temp[v]};
            }
            temp.insert(pair<int, int>(nums.at(i), i));
        }
        return vector<int>{-1, -1};
    }
};
