class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &visited, int nrow[], int ncol[], vector<vector<int>>& grid) {
        visited[row][col] = 1;
       
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i<4; i++) {
            int r = row + nrow[i];
            int c = col + ncol[i];

            if(r >=0 && r < n && c >= 0 && c < m && !visited[r][c] && grid[r][c] == 1) {
                dfs(r, c, visited, nrow, ncol, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int nrow[] = {-1, 0, +1, 0};
        int ncol[] = {0, +1, 0, -1};

        for(int i = 0; i<m; i++) {
            if(grid[0][i] == 1) {
                dfs(0, i, visited, nrow, ncol, grid);
            }
            if(grid[n-1][i] == 1) dfs(n-1, i, visited, nrow, ncol, grid);
        }
        for(int i = 0; i<n; i++) {
            if(grid[i][0] == 1) dfs(i, 0, visited, nrow, ncol, grid);
            if(grid[i][m-1] == 1) dfs(i, m-1, visited, nrow, ncol, grid);
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};