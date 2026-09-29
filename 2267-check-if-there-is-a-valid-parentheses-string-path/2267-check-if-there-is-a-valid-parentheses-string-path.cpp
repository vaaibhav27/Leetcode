class Solution {
public:

    bool solve(int i, int j, int balance,
               vector<vector<char>>& grid,
               vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if (balance < 0) {
            return false;
        }

        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        if (dp[i][j][balance] != -1) {
            return dp[i][j][balance];
        }

        bool down = false;

        if (i + 1 < m) {

            int newBalance = balance;

            if (grid[i + 1][j] == '(')
                newBalance++;
            else
                newBalance--;

            down = solve(i + 1, j, newBalance, grid, dp);
        }

        bool right = false;

        if (j + 1 < n) {

            int newBalance = balance;

            if (grid[i][j + 1] == '(')
                newBalance++;
            else
                newBalance--;

            right = solve(i, j + 1, newBalance, grid, dp);
        }

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        if (grid[0][0] == ')') {
            return false;
        }

        int len = m + n - 1;

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(len + 1, -1)
            )
        );

        int balance = 1;

        return solve(0, 0, balance, grid, dp);
    }
};

