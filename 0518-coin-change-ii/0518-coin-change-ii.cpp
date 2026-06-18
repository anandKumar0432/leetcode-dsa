class Solution {
public:
    int solve(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp) {
        
        if(idx < 0) {
            if(amount == 0) return 1;
            return 0;
        }
        if(amount == 0) return 1;

        if (dp[idx][amount] != -1) return dp[idx][amount];
        int take = 0;
        if (amount >= coins[idx]) take = solve(amount-coins[idx], coins, idx, dp);
        int notTake = solve(amount, coins, idx-1, dp);

        return dp[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(amount, coins, n-1, dp);
    }
};