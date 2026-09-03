class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if (n <= 1) return true;
        
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (int num : nums1) {
            if (num % 2 == 0) {
                minEven = min(minEven, num);
            } else {
                minOdd = min(minOdd, num);
            }
        }
        
        bool canMakeEven = true;
        for (int num : nums1) {
            if (num % 2 == 1) { 
                if (minOdd >= num || minOdd == INT_MAX) {
                    canMakeEven = false;
                    break;
                }
            }
        }
        
        bool canMakeOdd = true;
        for (int num : nums1) {
            if (num % 2 == 0) { 
                if (minOdd >= num || minOdd == INT_MAX) {
                    canMakeOdd = false;
                    break;
                }
            }
        }
        return canMakeEven || canMakeOdd;
    }
};