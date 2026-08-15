class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool flag = false;
        for(int x : nums) {
            xr ^= x;
            if(x != 0) flag = true;
        }
        if(xr != 0) return n;
        if(flag) return n-1;
        return 0;
    }
};