class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col){
        if(row == 0 && col == 0) return grid[row][col];
        if(row < 0 || col < 0) return 1e9;
        if(dp[row][col] != -1) return dp[row][col];

        long long left = grid[row][col] + solve(grid, dp, row-1, col);
        long long up = grid[row][col] + solve(grid, dp, row, col-1);

        return dp[row][col] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));
        return solve(grid, dp, row, col);
    }
};