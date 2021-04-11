class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int sArr[256] = {0};
        int tArr[256] = {0};
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            char sc = s[i];
            char tc = t[i];
            if(sArr[sc] != tArr[tc])
            {
                return false;
            }
            sArr[sc] = i + 1;
            tArr[tc] = i + 1;
        }
        return true;
    }
};
