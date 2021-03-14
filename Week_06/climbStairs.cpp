class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> cache(n);
        for(int i = 0; i < n; i++)
        {
            int target = i + 1; //当前台阶
            if(target <= 2) //当台阶数为1和2时，爬楼梯的方法也为1和2
            {
                cache[i] = target;
                continue;
            }
            cache[i] = cache[i - 1] + cache[i - 2]; //递推方程
        }
        return cache[n - 1];
    }
};
