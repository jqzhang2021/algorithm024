class Solution {
public:
   bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        int mark[26] = { 0 };
        for (auto& c : s)
        {
            mark[c - 'a'] += 1;
        }
       
        for (auto& c : t)
        {
            mark[c - 'a'] -= 1;
        }
        for (auto& i : mark)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
};
