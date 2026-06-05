// RECURSIVE (DP)

// class Solution {
// public:
//     int solve(vector<int>& nums, int idx, vector<int> &dp){
//         if(idx == 0) return nums[idx];
//         if(idx < 0) return 0;
        
//         if(dp[idx] != -1) return dp[idx];

//         int pick = nums[idx] + solve(nums, idx - 2, dp);
//         int notPick = solve(nums, idx - 1, dp);

//         return dp[idx] = max(pick, notPick);
//     }
    
//     int rob(vector<int>& nums) {
//         int size = nums.size();
//         int idx = nums.size() - 1;
//         vector<int> dp(size, -1);
//         return solve(nums, idx, dp);
//     }
// };





// Tabulation (DP)

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int size = nums.size();
//         vector<int> dp(size, -1);
        
//         dp[0] = nums[0];

//         for(int i = 1; i<size; i++){

//             int take = nums[i];
//             if(i-2 >= 0) take += dp[i-2];
//             int notTake = dp[i-1];

//             dp[i] = max(take, notTake);
//         }

//         return dp[size-1];
//     }
// };

// Space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, -1);
        
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i<size; i++){
            int take = nums[i];
            if(i-2 >= 0) take += prev2;
            int notTake = prev;

            int curri = max(take, notTake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};



