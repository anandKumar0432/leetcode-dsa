class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int n, vector<vector<vector<int>>>& dp, int limit, int allowedLimit){
        if(i == n ) return 0;
        int profit = 0;
        if(limit == allowedLimit) return 0;

        if(dp[i][buy][limit] != INT_MIN) return dp[i][buy][limit];
        if(buy){
            int take = -prices[i] + solve(prices, i+1, 0, n, dp, limit, allowedLimit);
            int notTake = 0 + solve(prices, i+1, 1, n, dp, limit, allowedLimit);
            profit =  max(take, notTake);
        }else{
            int take = prices[i] + solve(prices, i+1, 1, n, dp, limit+1, allowedLimit);
            int notTake = 0 + solve(prices, i+1, 0, n, dp, limit, allowedLimit);
            profit =  max(take, notTake);
        }

        return dp[i][buy][limit] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, INT_MIN)));
        return solve(prices, 0, 1, n, dp, 0, k);
    }
};