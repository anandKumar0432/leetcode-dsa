class Solution {
public:
    int minInsertions(string s) {
        string p = s;
        int n = s.size();
        reverse(s.begin(), s.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(p[i-1] == s[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // minimum insertion = s.size() - dp[n][n]
        return s.size() - dp[n][n];
    }
};