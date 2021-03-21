class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};
        for(int i=0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                int value = board[i][j]-'0' - 1;
                if(row[i][value]) return false; 
                if(col[j][value]) return false;
                int boxIndex = j/3 + (i/3)*3;
                if(box[boxIndex][value]) return false;
                row[i][value] = 1;
                col[j][value] = 1;
                box[boxIndex][value] = 1;
            }
        }
        return true;
    }
};
