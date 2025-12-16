
//-----------BIT MANIPULATION----------

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> arr;
//         int n = nums.size();
//         for(int i=0; i<(1<<n);i++){
//             for(int j=0; j<n; j++){
//                 if((i & (1<<j)) != 0){
//                     arr.push_back(nums[j]);
//                 }
//             }
//             res.push_back(arr);
//             arr.clear();
//         }
//         return res;
//     }
// };

//---------USING RECURSION(BACKTRACKING)------------
class Solution {
public:
    void subsequence(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &res){
        if(index >= nums.size()){
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[index]);
        subsequence(index+1, nums, arr, res);
        erase(arr, nums[index]);
        subsequence(index+1, nums, arr, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        subsequence(0, nums, arr, res);
        return res;
    }
};