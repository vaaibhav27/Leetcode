class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        long long sum = grid[i][j];

        grid[i][j] = 0;

        sum += dfs(i - 1, j, grid);
        sum += dfs(i + 1, j, grid);
        sum += dfs(i, j - 1, grid);
        sum += dfs(i, j + 1, grid);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);

                    if(sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};