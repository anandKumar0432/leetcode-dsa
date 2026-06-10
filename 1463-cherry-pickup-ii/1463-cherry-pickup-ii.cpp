class Solution {
public:
    int solve(vector<vector<int>>& grid,int row, int col1, int col2, int n, int m){
        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -1 * 1e9;
        if(row == n - 1) {
            if(col1 == col2) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
        int maxi = 0;

        for(int dj1=-1; dj1<2; dj1++){
            for(int dj2 = -1; dj2 < 2; dj2++){
                if(col1 == col2) maxi = max(maxi, grid[row][col1] + solve(grid, row+1, col1+dj1, col2 + dj2, n, m));
                else maxi = max(maxi, grid[row][col1] + grid[row][col2] + solve(grid, row+1, col1+dj1, col2+dj2, n, m));
            }
        }
        return maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(grid, 0, 0, m-1, n, m);
    }
};