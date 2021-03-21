class Solution {
public:
//剪枝版本（缓存中间结果）
    int climb(int n, vector<int>& cache)
    {
        if(n <= 2) return n;
        if(cache[n - 1] > 0) return cache[n - 1];
        cache[n] = climb(n - 1, cache) + climb(n - 2, cache);
        return cache[n];               
    }
    int climbStairs(int n) {
        vector<int> cache(n, 0);
        return climb(n, cache);
    }
};
