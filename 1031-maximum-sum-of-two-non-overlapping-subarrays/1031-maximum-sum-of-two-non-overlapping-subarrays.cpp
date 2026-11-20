
class Solution {
public:
    int maxSum(vector<int>& nums, int L, int M) {

        int n = nums.size();

        int sumL = 0, sumM = 0;

        for(int i = 0; i < L; i++)
            sumL += nums[i];

        for(int i = L; i < L + M; i++)
            sumM += nums[i];

        int maxL = sumL;
        int ans = sumL + sumM;

        for(int i = L + M; i < n; i++) {

            sumL += nums[i - M] - nums[i - M - L];

            maxL = max(maxL, sumL);

            sumM += nums[i] - nums[i - M];

            ans = max(ans, maxL + sumM);
        }

        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        return max(
            maxSum(nums, firstLen, secondLen),
            maxSum(nums, secondLen, firstLen)
        );
    }
};
