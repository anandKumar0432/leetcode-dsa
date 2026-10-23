class Solution {
public:
    bool isValid(vector<vector<int>>& matrix, int i, int j){
        int m = matrix.size();
        int n = matrix[0].size();
        if(i < 0 || i >= m) return false;
        if(j < 0 || j >= n) return false;

        return true;
    }
    int solve(vector<vector<int>>& matrix, int len, vector<int>& r, 
                vector<int>& c, int row, int col){
        int maxi = 1;
        for(int i=0; i<4; i++){
            if(isValid(matrix, row + r[i], col + c[i])){
                if(matrix[row+r[i]][col+c[i]] > matrix[row][col]){
                   maxi = max(maxi, 1 + solve(matrix, len+1, r, c, row+r[i], col+c[i]));
                }
            }
        }
        return maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<int> r = {-1, 1, 0, 0};
        vector<int> c = {0, 0, -1, 1};
        int len = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        int maxi = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int localMaxi = solve(matrix, len, r, c, i, j);
                maxi = max(localMaxi, maxi);
            }
        }

        return maxi;
    }
};