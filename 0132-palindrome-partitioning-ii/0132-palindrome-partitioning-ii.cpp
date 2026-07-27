class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else {
                return false;
            }
        }

        return true;
    }
    //------TLE ---------------
    // int solve(string& s, int i, int j, vector<vector<int>>& dp){
    //     if(i >= j) return 0;
         
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(isPalindrome(s, i, j)) return 0;
    //     int mini = INT_MAX;
    //     for(int k=i; k<j; k++){
    //         int left, right;
    //         if(dp[i][k] != -1) {
    //             left = dp[i][k];
    //         } else {
    //             left = solve(s, i, k, dp);
    //         }
            
    //         if(dp[k+1][j] != -1) {
    //             right = dp[k+1][j];
    //         } else{
    //             right = solve(s, k+1, j, dp);
    //         }

    //         int temp = 1 + left + right;
    //         if(temp < mini) mini = temp;
    //     }

    //     return dp[i][j] = mini;
    // }

// ---------- Recursive(no TLE);
    // int solve(string& s, int i, int n, vector<int>& dp){
    //     if(i == n) return 0;
        
    //     if(dp[i] != -1) return dp[i];
    //     int mini = INT_MAX;
    //     for(int j=i; j<n; j++){
    //         if(isPalindrome(s, i, j)){
    //             int temp = 1 + solve(s, j+1, n, dp);
    //             mini = min(mini, temp);
    //         }
    //     }

    //     return mini;
    // }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp (n+1, -1);
        // return solve(s, 0, n, dp) - 1;

        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int mini = INT_MAX;
            for(int j=i; j<n; j++){
                if(isPalindrome(s, i, j)){
                    int temp = 1 + dp[j+1];
                    mini = min(mini, temp);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};