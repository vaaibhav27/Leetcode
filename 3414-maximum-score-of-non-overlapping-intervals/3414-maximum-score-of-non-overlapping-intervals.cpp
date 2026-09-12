class Solution {
public:

    struct Node {
        int l, r;
        long long w;
        int idx;
    };

    struct State {
        long long score;
        vector<int> ans;
    };

    int n;
    vector<Node> a;
    vector<vector<int>> nextIndex;
    vector<vector<State>> dp;
    vector<vector<bool>> vis;

    State solve(int i, int k) {

        if (i == n || k == 0) {
            return {0, {}};
        }

        if (vis[i][k]) {
            return dp[i][k];
        }

        vis[i][k] = true;

        State skip = solve(i + 1, k);

        State takeNext = solve(nextIndex[i][0], k - 1);

        State take;

        take.score = a[i].w + takeNext.score;
        take.ans = takeNext.ans;
        take.ans.push_back(a[i].idx);

        sort(take.ans.begin(), take.ans.end());

        if (take.score > skip.score) {
            dp[i][k] = take;
        }
        else if (take.score < skip.score) {
            dp[i][k] = skip;
        }
        else {
            if (take.ans < skip.ans)
                dp[i][k] = take;
            else
                dp[i][k] = skip;
        }

        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        a.resize(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](Node &x, Node &y) {
            return x.l < y.l;
        });

        nextIndex.assign(n, vector<int>(1));

        for (int i = 0; i < n; i++) {

            int lo = i + 1;
            int hi = n;

            while (lo < hi) {

                int mid = lo + (hi - lo) / 2;

                if (a[mid].l > a[i].r)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nextIndex[i][0] = lo;
        }

        dp.assign(n, vector<State>(5));
        vis.assign(n, vector<bool>(5, false));

        return solve(0, 4).ans;
    }
};