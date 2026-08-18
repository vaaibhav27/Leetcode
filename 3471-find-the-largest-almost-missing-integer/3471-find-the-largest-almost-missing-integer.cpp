class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int x : nums) {
            mp[x]++;
        }
        int maxi = nums[0];
        if(k == n) {
            for(int i = 1; i < n; i++) {
                if(nums[i] > maxi) maxi = nums[i];
            }
            return maxi;
        }
        if(k == 1) {
            int ans = -1;
            for(auto x : mp) {
                if(x.second == 1) {
                    ans = max(ans, x.first);
                }
            }
            return ans;
        }
        int ans = -1;
        if(mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if(mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};