class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char, int> m;
        for(auto c : s)
        {
            if(m.count(c) == 0)
            {
                m.insert({c, 1});
            }
            else
            {
                m[c] += 1;
            }
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(m[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
