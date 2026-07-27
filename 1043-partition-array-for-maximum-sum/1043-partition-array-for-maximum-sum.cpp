class Solution {
public:
    int solve(vector<int>& arr, int i, int n, int k, vector<int>& dp){
        if(i == n) return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        if(dp[i] != -1) return dp[i];
        for(int j=i; j < min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int temp = len * maxi + solve(arr, j+1, n, k, dp);
            maxAns = max(maxAns, temp);
        }

        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, n, k, dp);
    }
};