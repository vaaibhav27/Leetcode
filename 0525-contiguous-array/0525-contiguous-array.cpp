class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int psum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) psum -= 1;
            else psum += 1;
            if(mp.find(psum) != mp.end()) {
                maxi = max(maxi, i - mp[psum]);
            }
            else mp[psum] = i;
        }
        return maxi;
    }
};