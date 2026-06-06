class Solution {
public:
    int maxNonAdjacentSum(vector<int>& nums, int idx, vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + maxNonAdjacentSum(nums, idx - 2, dp);
        int notPick = maxNonAdjacentSum(nums, idx - 1, dp);

        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();

        if(n == 1) return nums[0];
        
        for(int i = 0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);

        return max(maxNonAdjacentSum(temp1, n-2, dp1), maxNonAdjacentSum(temp2, n-2, dp2));
    }
};