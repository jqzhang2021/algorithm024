class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> r,d1,d2;
    int n;
    bool isValid(int row, int col) {
        if(r.count(row))
            return false;
        if(d1.count(col-row))
            return false;
        if(d2.count(col+row))
            return false;
        return true;
    }
    void fx(vector<string> &visited, int col) {
        if(col == n) {
            res.push_back(visited);
            return;
        }
        for(int row=0;row<n;row++) {
            if(!isValid(row,col))
                continue;

            visited[row][col] = 'Q';
            r.insert(row);
            d1.insert(col-row);
            d2.insert(col+row);

            fx(visited, col+1);

            visited[row][col] = '.';
            r.erase(row);
            d1.erase(col-row);
            d2.erase(col+row);
            
        }
    }
    vector<vector<string>> solveNQueens(int input) {
        n = input;
        vector<string> visited(n,string(n,'.'));
        fx(visited,0);
        
        return res;
    }
};
