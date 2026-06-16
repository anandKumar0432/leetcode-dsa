class Solution {
public:
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp){
        if(idx == 0){
            if(amount % coins[idx] == 0) return amount/coins[idx];
            return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = 0 + solve(coins, amount, idx-1, dp);
        int take = 1e9;
        if(coins[idx] <= amount) take = 1 + solve(coins, amount-coins[idx], idx, dp);

        return dp[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        if(solve(coins, amount, n-1, dp) == 1e9){
            return -1;
        }
        return solve(coins, amount, n-1, dp);
    }
};