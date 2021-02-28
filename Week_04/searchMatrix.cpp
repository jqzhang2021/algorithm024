class Solution {
public:
    int getMatrixSize(vector<vector<int>>& matrix)
    {
        return matrix.size() * matrix[0].size();
    }

    int getElementSize(vector<vector<int>>& matrix)
    {
        return matrix[0].size();
    }

    void convert(int index, int elementSize, int& x, int& y)
    {
        x = index / elementSize;
        y = index % elementSize;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int matrixSize = getMatrixSize(matrix);
        int elementSize = getElementSize(matrix);
        int left = 0;
        int right = matrixSize - 1;
        int middle = 0;
        int x = 0, y = 0;
        while(left <= right)
        {
            middle = left + (right - left) / 2;
            convert(middle, elementSize, x, y);
            if(matrix[x][y] == target)
            {
                return true;
            }
            if(matrix[x][y] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return false;
    }
};
