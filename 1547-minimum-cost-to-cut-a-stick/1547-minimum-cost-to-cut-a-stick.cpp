//---------MEMORY LIMIT EXCEEDED----------------------//

// class Solution {
// public:
//     int solve(map<int, int>& mp, int i, int j, vector<vector<int>>& dp){
//         if(i >= j) return 0;

//         int mini = INT_MAX;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         for(int k=i+1; k<j; k++){
//             if(mp.find(k) != mp.end()){
//                 int temp = j-i + solve(mp, i, k, dp) + solve(mp, k, j, dp);
//                 if(temp < mini) mini = temp;
//             }
//         }

//         return dp[i][j] = mini == INT_MAX ? 0 : mini;
//     }
//     int minCost(int n, vector<int>& cuts) {
        
//         map<int, int> mp;
//         for(int i=0; i<cuts.size(); i++){
//             mp[cuts[i]] = i; 
//         }
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solve(mp, 0, n, dp);
//     }
// };




class Solution {
public:
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(j-i == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=i+1; k<j; k++){
            int temp = cuts[j] - cuts[i] + solve(cuts, i, k, dp) + solve(cuts, k, j, dp);
            mini = min(mini, temp);
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(cuts, 0, m-1, dp);
    }
};