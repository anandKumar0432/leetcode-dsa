class Solution {
public:
    string reverseString(string s){
        string str = "";
        for(int i = s.size() - 1; i>=0; i--){
            str += s[i];
        }
        return str;
    }
    int longestPalindromeSubseq(string s) {
        int n1 = s.size();
        string s2 = reverseString(s);
        int n2 = s2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(s[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n1][n2];
    }
};