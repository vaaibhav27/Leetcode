class Solution {
public:
    int solve(int &n, int &m, int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        if(i >= n || j >= m) return 0;

        if(obstacleGrid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(i == n-1 && j == m-1) return 1;

        int d = solve(n, m, i+1, j, obstacleGrid, dp);

        int r = solve(n, m, i, j+1, obstacleGrid, dp);

        return dp[i][j] = d + r;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n, m, 0, 0, obstacleGrid, dp);
    }
};