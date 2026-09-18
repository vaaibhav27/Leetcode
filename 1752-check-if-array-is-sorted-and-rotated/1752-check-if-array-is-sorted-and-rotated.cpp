class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] > nums[i]) cnt++;
        }
        if(nums[0] < nums[n-1]) cnt++;
        return cnt <= 1;
    }
};