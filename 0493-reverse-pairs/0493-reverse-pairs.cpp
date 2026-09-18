class Solution {
public:
    void ms(vector<int>& nums, int low, int mid, int high) {
        int l = low;
        int r = mid+1;
        vector<int> temp;
        while(l<= mid && r<= high) {
            if(nums[l]<= nums[r]) {
                temp.push_back(nums[l++]);
            }
            else {
                temp.push_back(nums[r++]);
            }
        }
        while(l<=mid) {
            temp.push_back(nums[l++]);
        }
        while(r<= high) {
            temp.push_back(nums[r++]);
        }

        for(int i = low; i<= high; i++) {
            nums[i] = temp[i-low];
        }
    }
    int magic(vector<int>& nums, int low, int mid, int high) {
        int r = mid+1;
        int cnt = 0;
        for(int i = low; i<= mid; i++) {
            while(r<= high && nums[i] > 2LL * nums[r]) {
                r++;
            }
            cnt+= (r-(mid+1));
        }
        return cnt;
    }
    int mergesort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if(low>= high) return cnt;
        int mid = low + (high-low)/2;
        cnt+= mergesort(nums, low, mid);
        cnt+= mergesort(nums, mid+1, high);
        cnt+= magic(nums, low, mid, high);
        ms(nums, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums, 0, n-1);
    }
};