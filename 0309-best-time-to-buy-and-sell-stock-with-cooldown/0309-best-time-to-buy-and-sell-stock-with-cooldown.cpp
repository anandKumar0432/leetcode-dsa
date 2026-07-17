class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int n, vector<vector<int>>& dp){

        if(i >= n) return 0;

        if(dp[i][buy] != INT_MIN) return dp[i][buy];
        int profit = 0;
        if(buy){
            int take = -prices[i] + solve(prices, i+1, 0, n, dp);
            int notTake = 0 + solve(prices, i+1, 1, n, dp);
            profit = max(take, notTake);
        } else{
            int take = prices[i] + solve(prices, i+2, 1, n, dp);
            int notTake = 0 + solve(prices, i+1, 0, n, dp);
            profit = max(take, notTake);
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        return solve(prices, 0, 1, n, dp);
    }
};