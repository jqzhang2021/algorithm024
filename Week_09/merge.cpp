class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() <= 1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        int index = 0;
        vector<int> current = intervals[index];
        while(index < intervals.size() - 1)
        {
            vector<int> next = intervals[index + 1];
            if(next[0] > current[1])
            {
                result.push_back(current);
                current = next;
            }
            else
            {
                current[1] = max(current[1], next[1]);
            }
            index += 1;
        }
        result.push_back(current);
        return result;
    }
};
