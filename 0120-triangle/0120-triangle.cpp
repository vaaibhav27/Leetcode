
class Solution {
public:
    int solve(int &n, int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        if(i == n-1) return triangle[i][j];

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int s = triangle[i][j] + solve(n, i+1, j, triangle, dp);

        int d = triangle[i][j] + solve(n, i+1, j+1, triangle, dp);

        return dp[i][j] = min(s, d);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        return solve(n, 0, 0, triangle, dp);
    }
};
