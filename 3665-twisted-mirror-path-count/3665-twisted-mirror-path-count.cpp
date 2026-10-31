
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<long long> down(n, 0);

        for (int i = 0; i < m; i++) {
            long long right = 0;

            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    right = 1;
                    down[j] = 1;
                    continue;
                }

                long long fromTop = down[j];
                long long fromLeft = right;

                if (grid[i][j] == 1) {
                    down[j] = fromLeft;
                    right = fromTop;
                }
                else {
                    long long total = (fromTop + fromLeft) % MOD;

                    down[j] = total;
                    right = total;
                }
            }
        }

        return down[n - 1];
    }
};
