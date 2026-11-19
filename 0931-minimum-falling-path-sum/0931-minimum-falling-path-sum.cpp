
class Solution {
public:
    int solve(int &n, int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

        if(j < 0 || j >= n) return INT_MAX;

        if(i == n-1) return matrix[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int s = solve(n, i+1, j, matrix, dp);
        int l = solve(n, i+1, j-1, matrix, dp);
        int r = solve(n, i+1, j+1, matrix, dp);

        int mini = min({s, l, r});

        if(mini == INT_MAX) return dp[i][j] = INT_MAX;

        return dp[i][j] = matrix[i][j] + mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(n, 0, j, matrix, dp));
        }

        return ans;
    }
};
