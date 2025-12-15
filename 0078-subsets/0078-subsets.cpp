class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        int n = nums.size();
        for(int i=0; i<(1<<n);i++){
            for(int j=0; j<n; j++){
                if((i & (1<<j)) != 0){
                    arr.push_back(nums[j]);
                }
            }
            res.push_back(arr);
            arr.clear();
        }
        return res;
    }
};