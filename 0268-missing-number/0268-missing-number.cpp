class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i = 0; i < n; i++) {
            ans ^= nums[i];
            ans ^= i;
        }
        return ans;
    }
};