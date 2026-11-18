class Solution {
public:
    int solve(int &n, int &m, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i >= n || j >= m) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        if(i == n-1 && j == m-1) return grid[i][j];

        int d = grid[i][j] + solve(n, m, i+1, j, grid, dp);

        int r = grid[i][j] + solve(n, m, i, j+1, grid, dp);

        return dp[i][j] = min(d, r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return solve(n, m, 0, 0, grid, dp);
    }
};