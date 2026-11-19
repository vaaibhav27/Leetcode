
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        int n = triangle.size();

        if(i == n - 1)
            return triangle[i][j];

        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        int down = solve(i + 1, j, triangle, dp);

        int diagonal = solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        return solve(0, 0, triangle, dp);
    }
};
