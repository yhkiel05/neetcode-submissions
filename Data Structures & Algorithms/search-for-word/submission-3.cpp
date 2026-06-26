class Solution {
public:
    int rows, cols;
    set<pair<int,int>> paths;

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) return true; 
            }
        }
        return false;    
    }
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) return true;
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[i] || paths.count({r,c})) {
            return false;
        }
        // younghoon is gay ;c 
        paths.insert({r,c});
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);
        paths.erase({r,c});
        return res;

    }
};
