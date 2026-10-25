class Solution {
public:
    int n, m;

    void dfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= n || col >= m ||
            grid[row][col] == 1) {
            return;
        }

        grid[row][col] = 1;

        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);  
        dfs(row, col - 1, grid);  
        dfs(row, col + 1, grid);  
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();


        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                dfs(i, 0, grid);
            }

            if (grid[i][m - 1] == 0) {
                dfs(i, m - 1, grid);
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) {
                dfs(0, j, grid);
            }

            if (grid[n - 1][j] == 0) {
                dfs(n - 1, j, grid);
            }
        }


        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};