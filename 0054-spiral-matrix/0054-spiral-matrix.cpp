class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
         int dir = 0;
         // top : top +1;
         //bottom : bottom-1;
         //right : right - 1;
         //left : left+1;
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(top <= bottom && left <= right){
            if(dir == 0){
                for(int i=left; i<=right; i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir == 1){
                for(int i=top; i<=bottom; i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir == 2){
                for(int i=right; i>=left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(dir == 3){
                for(int i=bottom; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir == 4){
                dir = 0;
            }

        }
        return result;
    }
};