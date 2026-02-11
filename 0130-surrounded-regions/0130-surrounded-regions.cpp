class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue<pair<int, int>> q;
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,-1,1};

        int i=0;
        for(int j = 0; j < col; j++){
            if(board[i][j] == 'O'){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
        i=row-1;
        for(int j = 0; j < col; j++){
            if(board[i][j] == 'O'){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
        int j = 0;
        for(int i = 0; i < row; i++){
            if(board[i][j] == 'O'){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
        j = col-1;
        for(int i = 0; i < row; i++){
            if(board[i][j] == 'O'){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && !vis[nr][nc] && board[nr][nc] == 'O'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        for(int i = 0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                    vis[i][j] = 1;
                }
            }
        }
    }
};