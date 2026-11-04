
class Solution {
public:
    multiset<int> left, right;
    long long sumL = 0, sumR = 0;

    void add(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumL += val;
        } else {
            right.insert(val);
            sumR += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumL -= val;
        } else {
            it = right.find(val);
            right.erase(it);
            sumR -= val;
        }

        balance();
    }

    void balance() {
        while (left.size() > right.size() + 1) {
            int val = *left.rbegin();
            left.erase(prev(left.end()));
            sumL -= val;

            right.insert(val);
            sumR += val;
        }

        while (left.size() < right.size()) {
            int val = *right.begin();
            right.erase(right.begin());
            sumR -= val;

            left.insert(val);
            sumL += val;
        }
    }

    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - sumL
             + sumR - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
