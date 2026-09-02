class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int d = nums[i];
            int cnt = 0;
            while(d) {
                int rem = d % 10;
                cnt++;
                d /= 10;
            }
            if(cnt % 2 == 0) ans++;
        }
        return ans;
    }
};