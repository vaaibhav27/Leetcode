class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = prices[0];
        int p = 0;
        for(int i = 1; i < n; i++) {
            int profit = prices[i] - cost;
            p = max(p, profit);
            cost = min(cost, prices[i]);
        }
        return p;
    }
};