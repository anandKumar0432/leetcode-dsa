class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat[0].size(); // column size
        int start=0;
        int end = n-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            int row = -1;
            int maxVal = INT_MIN;
            for(int i=0; i<mat.size(); i++){
                if(maxVal < mat[i][mid]){
                    maxVal = mat[i][mid];
                    row = i;
                }
            }
            int left = -1;
            int right = -1;
            if(mid-1 >= 0){
                left = mat[row][mid-1];
            }
            if(mid+1 < n){
                right = mat[row][mid+1];
            }

            if(left > maxVal){
                end = mid - 1;
            }else if(right > maxVal){
                start = mid + 1;
            }else{
                return {row, mid};
            }
        }
        return {-1, -1};
    }
};