
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;

        for (int x : aliceSizes) {
            sumA += x;
        }

        for (int x : bobSizes) {
            sumB += x;
        }

        int diff = (sumB - sumA) / 2;

        unordered_set<int> st;

        for (int x : bobSizes) {
            st.insert(x);
        }

        for (int x : aliceSizes) {
            int y = x + diff;

            if (st.count(y)) {
                return {x, y};
            }
        }

        return {};
    }
};
