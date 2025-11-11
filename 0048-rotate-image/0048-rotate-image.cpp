class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0;
        int bottom = row-1;

        while(top < bottom){
            for(int i = 0; i<col; i++){
                swap(matrix[top][i], matrix[bottom][i]);
            }
            top++;
            bottom--;
        }

        for(int i = 0; i<row; i++){
            for(int j = i; j<col; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};