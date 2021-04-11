class Solution {
public:
    void swap(char& s, char& t)
    {
        char temp = s;
        s = t;
        t = temp;
    }

    void reverse(string& s, int begin, int end)
    {
        int step = (end - begin) >> 1;
        for(int i = 0; i <= step; i++)
        {
            swap(s[begin + i] , s[end - i]);
        }
    }

    //整体反转
    string reverseStr(string& s)
    {
        string temp;
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            temp.push_back(s[size - 1 - i]);
        }
        return temp;
    }

    //去头掐尾
    string trim(string& temp)
    {
        int begin = 0;
        while(temp[begin] == ' ')
        {
            begin += 1;
        }
        int end = temp.size() - 1;
        while(temp[end] == ' ')
        {
            end -= 1;
        }
        return temp.substr(begin, end - begin + 1);
    }

    string removeSpace(string& s)
    {
        string result;
        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] != ' ')
            {
                result.push_back(s[i]);
            }
            else
            {
                if(result[result.size() - 1] != ' ')
                {
                    result.push_back(' ');
                }
            }
        }
        return result;
    }

    string reverseWords(string s) 
    {
        string temp = trim(s);
        temp = removeSpace(temp);
        temp = reverseStr(temp);
        
        int b = 0;
        for(int i = 0; i < temp.size(); i++)
        {
            if(temp[i] == ' ')
            {
                reverse(temp, b, i - 1);
                b = i + 1;
            }
        }
        reverse(temp, b, temp.size() - 1);
        return temp;
    }
};
