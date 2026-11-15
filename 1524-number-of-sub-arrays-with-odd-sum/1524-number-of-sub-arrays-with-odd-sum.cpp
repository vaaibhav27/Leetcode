class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;

        int odd = 0, even = 1;
        int sum = 0, ans = 0;

        for(int x : arr) {
            sum += x;

            if(sum % 2 == 0) {
                ans = (ans + odd) % mod;
                even++;
            }
            else {
                ans = (ans + even) % mod;
                odd++;
            }
        }

        return ans;
    }
};