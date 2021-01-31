#include <vector>
using std::vector;


class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n + 1, 0);
        vec[0] = 1;
        vec[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2]; //动态规划解法：到达n阶的方法等于到达n-1阶和n-2阶的方法之和
        }
        return vec[n];
    }
};
