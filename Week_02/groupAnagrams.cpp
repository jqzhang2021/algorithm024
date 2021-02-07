class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for(auto& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            if(map.find(key) == map.end())
            {
                map[key] = vector<string>{};
            }
            map[key].push_back(s);
        }
        for(auto& kvp : map)
        {
            result.push_back(move(kvp.second));
        }
        return result;
    }
};
