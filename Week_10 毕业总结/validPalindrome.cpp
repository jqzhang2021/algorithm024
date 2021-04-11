class Solution {
public:
    bool valid(string& s, int low, int high)
    {
        for(int i = low, j = high; i < j; i++, j--)
        {
            if(s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        int low = 0, high = s.size() - 1;
        while(low < high)
        {
            if(s[low] == s[high])
            {
                low += 1;
                high -= 1;
            }
            else
            {
                return valid(s, low, high - 1) || valid(s, low + 1, high);
            }
        }
        return true;
    }
};
