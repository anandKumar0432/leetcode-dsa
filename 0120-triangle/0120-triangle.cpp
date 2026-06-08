class Solution {
public:
    int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row, int col){
        if(row == triangle.size() - 1) return triangle[row][col];

        if(row >= triangle.size() || col >= triangle[row].size()) return 1e9;

        if(dp[row][col] != -1* 1e9) return dp[row][col];

        int same = triangle[row][col] + solve(triangle, dp, row+1, col);
        int adj = triangle[row][col] + solve(triangle, dp, row+1, col+1);

        return dp[row][col] = min(same, adj);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1 * 1e9));
        return solve(triangle, dp, 0, 0);
    }
};