class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int size){
        if(row >= size || col >= size || col < 0) return 1e9;
        if(row == matrix.size()-1) return matrix[row][col];

        if(dp[row][col] != -1 * 1e9) return dp[row][col];

        int below = matrix[row][col] + solve(matrix, dp, row+1, col, size);
        int dLeft = matrix[row][col] + solve(matrix, dp, row+1, col-1, size);
        int dRight = matrix[row][col] + solve(matrix, dp, row+1, col+1, size);

        return dp[row][col] = min(below, min(dLeft, dRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>>dp(size, vector<int>(size, -1 * 1e9));
        for(int i=0; i<size; i++){
            mini = min(mini, solve(matrix, dp, 0, i, size));
        }

        return mini;
    }
};