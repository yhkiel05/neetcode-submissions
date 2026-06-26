class Solution {
public:
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';
        queue<pair<int,int>> q;
        q.push({row, col});
        while (!q.empty()) {
            auto pair = q.front();
            q.pop();
            int r = pair.first;
            int c = pair.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                    //bfs(grid, nr, nc);
                }
            }
        }
    }
};
