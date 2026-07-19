class Solution {
public:
    // int solve(vector<int>& nums, int n, int i, int prevIdx, vector<vector<int>>& dp){
    //     if(i == n) return 0;
    //     if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];
    //     int len = solve(nums, n, i+1, prevIdx, dp);
    //     if(prevIdx == -1 || nums[i] > nums[prevIdx]){
    //         len = max(len, 1+solve(nums, n, i+1, i, dp));
    //     }
    //     return dp[i][prevIdx+1] = len;
    // }

    //-------------TABULATION------------------------
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    //     for(int i=n-1; i>=0; i--){
    //         for(int prevIdx = i-1; prevIdx>=-1; prevIdx--){
    //             int len = dp[i+1][prevIdx+1];
    //             if(prevIdx == -1 || nums[i] > nums[prevIdx]){
    //                 len = max(len, 1 + dp[i+1][i+1]);
    //             }
    //             dp[i][prevIdx+1] = len;
    //         }
    //     }

    //     return dp[0][-1+1];
    // }


    //--------TABULATION-2---------------
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(1+dp[prev], dp[i]);
                }
            }
        }

        int maxi = 0;
        for(int i = 0; i<n; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }

        return maxi;
    }
};