class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        vector<int> psum(n);
        psum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            psum[i] = psum[i-1] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            int rem = psum[i] % k;
            if(mp.find(rem) != mp.end()) {
                if(i - mp[rem] >= 2) return true;
            }
            else mp[rem] = i;
        }
        
        return false;
    }
};