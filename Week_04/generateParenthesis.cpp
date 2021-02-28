class Solution {
public:
    void generate(int left, int right, int max, string current, vector<string>& result)
    {
        if(left == max && right == max)
        {
            result.push_back(current);
            return;
        }
        if(left < max)
        {
            generate(left + 1, right, max, current + "(", result);
        }
        if(right < left)
        {
            generate(left, right + 1, max, current + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(0, 0, n, "", result);
        return result;
    }
};
