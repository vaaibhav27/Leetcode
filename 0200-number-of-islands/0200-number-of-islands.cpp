class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int col, int &count) {

        grid[row][col] = '0';
        int n = grid.size();
        int m = grid[0].size();

        int nrow[] = {-1, 1, 0, 0};
        int ncol[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int r = nrow[i] + row;
            int c = ncol[i] + col;

            if(r >=0 && r < n && c >=0 && c < m && grid[r][c] == '1') {
                dfs(grid, r, c, count);
            } 
        }

    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {

                    count++;

                    dfs(grid, i, j, count);
                }
            }
        }

        return count;
    }
};