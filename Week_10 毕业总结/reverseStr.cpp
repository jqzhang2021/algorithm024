class Solution {
public:
    void swap(char& a, char& b)
    {
        char temp = a;
        a = b;
        b = temp;
    }
    void reverse(string& s, int start, int end)
    {
        int size = s.size();
        if(start < 0 || end >= size) return;
        int i = start;
        int j = end;
        while(i < j)
        {
            swap(s[i], s[j]);
            i += 1;
            j -= 1;
        }
    }
    string reverseStr(string s, int k) 
    {
        if(k == 1) return s;
        int size = s.size();
        int dk = 2 * k;
        for(int i = 0; (i + dk) <= size; i += dk)
        {
            reverse(s, i, i + k - 1);
        }
        int left = size % dk;
        if(left == 0) return s;
        if(left < k)
        {
            reverse(s, size - left, size - 1);
        }
        else
        {
            reverse(s, size - left, size - left + k - 1);
        }
        return s;
    }
};
