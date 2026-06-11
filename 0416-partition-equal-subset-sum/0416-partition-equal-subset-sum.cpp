class Solution {
public:
    bool solve(vector<int>& nums, vector<vector<int>>& dp, int idx, int halfSum){
        if(halfSum == 0) return true;
        if(idx == 0){
            if(halfSum != 0) return false;
            return true;
        }
        if(halfSum < 0) return false;
        if(dp[idx][halfSum] != -1) return (dp[idx][halfSum] == 1);
        int pick = solve(nums, dp, idx-1, halfSum-nums[idx]);
        int notPick = solve(nums, dp, idx-1, halfSum);

        return dp[idx][halfSum] = (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }

        if(sum % 2 != 0){
            return false;
        }

        vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));

        return solve(nums, dp, n-1, sum/2);
    }
};