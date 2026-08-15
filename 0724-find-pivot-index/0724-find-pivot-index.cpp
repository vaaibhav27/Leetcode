class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) {
            sum += x;
        }
        int p_sum = 0;
        for(int i = 0; i < n; i++) {
            p_sum += nums[i];
            if(p_sum == sum) return i;
            sum -= nums[i];
        }
        return -1;
    }
};