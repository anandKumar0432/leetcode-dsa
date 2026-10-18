class Solution {
public:
    bool isValid(int i, int j, int n, vector<string> &board){
        int a,b;
        a=i; b=j;

        while(a >= 0 && b >= 0){
            if(board[a][b] != '.') return false;
            a--; b--;
        }
        a=i; b=j;
        while(a >= 0 && b < n){
            if(board[a][b] != '.') return false;
            a--; b++;
        }

        for(int k=0; k<i; k++){
            if(board[k][j] != '.') return false;
        }

        return true;
    }
    void solve(int start,vector<string> &board, vector<vector<string>> &res, int n){
        
        if(start == n){
            res.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(isValid(start, j, n, board)){
                board[start][j] = 'Q';
                solve(start+1, board, res, n);
                board[start][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(0, board, res, n);
        return res;
    }
};