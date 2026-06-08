class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int row, int col){
        if(row < 0 || col < 0) return 0;
        if(obstacleGrid[row][col] == 1) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int left = solve(obstacleGrid, dp, row - 1, col);
        int up = solve(obstacleGrid, dp, row, col - 1);

        return dp[row][col] = left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size() - 1;
        int col = obstacleGrid[0].size() - 1;

        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));
        return solve(obstacleGrid, dp, row, col);
    }
};