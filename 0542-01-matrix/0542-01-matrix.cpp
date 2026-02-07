class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(row, vector<bool> (col, false));
        vector<vector<int>> outMatrix(row, vector<int> (col, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 0){
                    outMatrix[i][j] = 0;
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && 
                            !visited[nr][nc] && mat[nr][nc] == 1){
                        outMatrix[nr][nc] = outMatrix[r][c] + 1;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        return outMatrix;
    }
};