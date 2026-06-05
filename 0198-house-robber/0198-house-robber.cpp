class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int> &dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int pick = nums[idx] + solve(nums, idx - 2, dp);
        int notPick = solve(nums, idx - 1, dp);

        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int idx = nums.size() - 1;
        vector<int> dp(size, -1);
        return solve(nums, idx, dp);
    }
};