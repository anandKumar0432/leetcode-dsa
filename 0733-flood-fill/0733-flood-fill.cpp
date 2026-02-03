class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = true;
        int start = image[sr][sc];
        image[sr][sc] = color;

        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            if(ele.first-1 >= 0 && image[ele.first - 1][ele.second] == start && !visited[ele.first - 1][ele.second]){
                image[ele.first - 1][ele.second] = color;
                q.push({ele.first-1, ele.second});
                visited[ele.first - 1][ele.second] = true;
            }else{
               if(ele.first-1 >= 0) visited[ele.first - 1][ele.second] = true;
            }
            if(ele.first+1 <= row-1 && image[ele.first + 1][ele.second] == start && !visited[ele.first + 1][ele.second]){
                image[ele.first + 1][ele.second] = color;
                q.push({ele.first+1, ele.second});
                visited[ele.first + 1][ele.second] = true;
            }else{
                if(ele.first+1 <= row-1) visited[ele.first + 1][ele.second] = true;
            }
            if(ele.second + 1 <= col-1 && image[ele.first][ele.second+1] == start && !visited[ele.first][ele.second+1]){
                image[ele.first][ele.second+1] = color;
                q.push({ele.first, ele.second+1});
                visited[ele.first ][ele.second+1] = true;
            }else{
                if(ele.second + 1 <= col-1) visited[ele.first][ele.second+1] = true;
            }
            if(ele.second-1 >= 0 && image[ele.first][ele.second - 1] == start && !visited[ele.first][ele.second-1]){
                image[ele.first][ele.second - 1] = color;
                q.push({ele.first, ele.second - 1});
                visited[ele.first][ele.second - 1] = true;
            }else{
                if(ele.second-1 >= 0) visited[ele.first][ele.second - 1] = true;
            }
        }
        return image;
    }
};