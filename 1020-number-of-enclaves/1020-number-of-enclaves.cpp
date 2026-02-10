class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, 0));
        queue<pair<int, int>> q;
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        int i=0;
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 1){
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
        i=row-1;
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 1){
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
        int j = 0;
        for(int i = 0; i < row; i++){
            if(grid[i][j] == 1){
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
        j = col-1;
        for(int i = 0; i < row; i++){
            if(grid[i][j] == 1){
                visited[i][j] = 1;
                q.push({i,j});
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nc >= 0 && nc < col && nr >= 0 && nr < row && 
                        grid[nr][nc] == 1 && !visited[nr][nc]){

                            visited[nr][nc] = 1;
                            q.push({nr,nc});
                }
            }
        }

        int count = 0;
        for(int k=1; k<row-1; k++){
            for(int l=1; l<col-1; l++){
                if(grid[k][l] == 1 && !visited[k][l]){
                    count++;
                }
            }
        }

        return count;
    }
};