class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int x = triangle.size();
        //从下往上，从倒数第二行开始
        for(int i = x - 2; i >= 0; i--)
        {
            //当前行元素个数
            int y = triangle[i].size();
            for(int j = 0; j < y; j++)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
