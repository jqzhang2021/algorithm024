class Solution {
public:
    void mark(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
        {
            return;
        }
        if(grid[i][j] == '1')
        {
            grid[i][j] = '0';
            mark(grid, i - 1, j);
            mark(grid, i + 1, j);
            mark(grid, i, j - 1);
            mark(grid, i, j + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    mark(grid, i, j);
                }
            }
        }
        return count;
    }
};
