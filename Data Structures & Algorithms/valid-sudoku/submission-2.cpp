class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int,int>, unordered_set<char>> grids;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                pair<int, int> grid = {i / 3, j / 3};
                if (board[i][j] != '.') {
                    if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || grids[grid].count(board[i][j])) {
                        return false;
                    }
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                grids[grid].insert(board[i][j]);
            }
        }
        return true;
    }
};
