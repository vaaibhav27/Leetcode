class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            if (i > 0)
                dp[i] = dp[i - 1];

            for (int j = 0; j <= i; j++) {

                int len = i - j + 1;

                if (len >= k && pal[j][i]) {

                    if (j == 0)
                        dp[i] = max(dp[i], 1);
                    else
                        dp[i] = max(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};