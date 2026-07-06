// THIS GIVES MEMORY LIMIT EXCEEDED??????????????????

// class Solution {
// public:
//     int solve(string s, string t, int idx, string str){

//         string temp = str;
//         reverse(temp.begin(), temp.end());
//         if(temp == t) return 1;

//         if(idx < 0){
//             if(temp == t) return 1;
//             else return 0;
//         }

//         int take = solve(s, t, idx-1, str+s[idx]);
//         int notTake = solve(s, t, idx-1, str);

//         return (take + notTake);
//     }
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         return solve(s, t, n-1, "");
//     }
// };




class Solution {
public:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp){

        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = solve(s, t, i-1, j-1, dp) + solve(s, t, i-1, j, dp);
        }
        return dp[i][j] = solve(s, t, i-1, j, dp);
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(s, t, n1-1, n2-1, dp);
    }
};



