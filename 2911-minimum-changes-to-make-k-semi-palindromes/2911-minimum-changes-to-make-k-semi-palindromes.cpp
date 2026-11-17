
class Solution {
public:
    int dp[205][105];
    int cost[205][205];

    void precompute(string &s) {
        int n = s.size();

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;
                cost[l][r] = INT_MAX;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int i = 0; i < d; i++) {
                        int left = l + i;
                        int right = l + i + (len / d - 1) * d;

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }
    }

    int solve(int i, int k, int n) {
        if (k == 0)
            return i == n ? 0 : 1e9;

        if (n - i < 2 * k)
            return 1e9;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = 1e9;

        for (int j = i + 1; j <= n - 2 * (k - 1); j++) {
            int curr = cost[i][j];

            int remaining = solve(j + 1, k - 1, n);

            ans = min(ans, curr + remaining);
        }

        return dp[i][k] = ans;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();

        memset(dp, -1, sizeof(dp));

        precompute(s);

        return solve(0, k, n);
    }
};
