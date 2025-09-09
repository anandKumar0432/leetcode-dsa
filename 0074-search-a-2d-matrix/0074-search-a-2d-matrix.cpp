class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int srow = 0;
        int erow = matrix.size()-1;
        
        while(srow<=erow){
            int rowMid = srow + (erow - srow)/2;
            int scol = 0;
            int ecol = matrix[0].size()-1;
            while(scol <= ecol){
                int colMid = scol + (ecol - scol)/2;
                if(matrix[rowMid][colMid] == target){
                    return true;
                }else if(matrix[rowMid][colMid] > target){
                    ecol = colMid - 1;
                }else{
                    scol = colMid+1;
                }
            }
            if(matrix[rowMid][0] > target){
                erow = rowMid - 1;
            }else{
                srow = rowMid + 1;
            }
        }
        return false;
    }
};