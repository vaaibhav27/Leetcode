class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int psum = 0;
        int maxi = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            psum += nums[i];
            int diff = psum - k;
            if(mp.find(diff) != mp.end()) maxi+=mp[diff];
            mp[psum]++;
        }
        return maxi;
    }
};