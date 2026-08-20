class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int l = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while(i - l + 1 > k) {
                sum -= nums[l];
                l++;
            }
            if(i-l+1 == k) maxi = max(maxi, sum);
        }
        return (double)maxi/k;
    }
};