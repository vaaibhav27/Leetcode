class Solution {
public:

    long long countWays(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            long long lcm = 1;
            bool valid = true;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    long long g = gcd(lcm, (long long)coins[i]);

                    lcm = (lcm / g) * coins[i];

                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long cnt = x / lcm;

            if (bits % 2 == 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }


    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = *min_element(coins.begin(), coins.end());

        long long high = low * 1LL * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countWays(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};