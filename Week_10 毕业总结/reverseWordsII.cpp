class Solution {
public:
    //前闭后开区间
    void reverse(string& s, int begin, int end)
    {
        int step = (end - begin) / 2;
        for(int i = 0; i < step; i++)
        {
            int left = begin + i;
            int right = end - i - 1;
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
        }
    }

    string reverseWords(string s) 
    {
        int index = -1;
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            char current = s[i];
            if(current != ' ' && index == -1)
            {
                index = i;
            }
            else if(current == ' ')
            {
                reverse(s, index, i);
                index = -1;
            }
        }
        reverse(s, index, size);
        return s;
    }
};
