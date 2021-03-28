class TrieNode{
public:
    string word = "";
    vector<TrieNode*> nodes;
    TrieNode():nodes(26, 0){}
};

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        int m = board.size();
        int n = (m == 0 ? 0 : board[0].size());
        if(m==0 || n==0) return result;

        //建立字典树
        TrieNode* root = new TrieNode();
        for(auto word:words){
            TrieNode *cur = root;
            for(int i = 0; i < word.size(); ++i){
                int idx = word[i]-'a';
                if(cur->nodes[idx]==0) cur->nodes[idx] = new TrieNode();
                cur = cur->nodes[idx];
            }
            cur->word = word;
        }

        //DFS模板
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                dfs(result, board, root, i, j, m, n);
            }
        }
        return result;
    }

    void dfs(vector<string>& result, vector<vector<char>>& board, TrieNode* root, int x, int y, int m, int n){
        char c = board[x][y];
        //递归边界
        if(c=='.' || root->nodes[c-'a']==0) return;
        root = root->nodes[c-'a'];
        if(root->word!="")
        {
            result.push_back(root->word);
            root->word = "";
        }
        
        board[x][y] = '.';
        if(x > 0) dfs(result, board, root, x-1, y, m, n);
        if(y > 0) dfs(result, board, root, x, y-1, m, n);
        if(x + 1 < m) dfs(result, board, root, x+1, y, m, n);
        if(y + 1 < n) dfs(result, board, root, x, y+1, m, n);
        board[x][y] = c;
    }  
};
