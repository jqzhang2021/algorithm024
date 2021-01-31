#include <vector>
using std::vector;

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        unordered_map<char, char> map = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
        for (int i = 0; i < (int)s.size(); i++)
        {
            char c = s[i];
            if (map.find(c) != map.end())
            {
                st.push(c);
            }
            else
            {
                if (st.size() > 0 && c == map[st.top()])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
