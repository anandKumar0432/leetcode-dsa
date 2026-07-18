class Solution {
public:
    int solve(vector<int>& nums, int n, int i, int prevIdx, vector<vector<int>>& dp){
        if(i == n) return 0;
        if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];
        int len = solve(nums, n, i+1, prevIdx, dp);
        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            len = max(len, 1+solve(nums, n, i+1, i, dp));
        }
        return dp[i][prevIdx+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, n, 0, -1, dp);
    }
};