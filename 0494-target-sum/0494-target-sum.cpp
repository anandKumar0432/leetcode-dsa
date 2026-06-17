class Solution {
public:
    int solve(vector<int>& nums, int target, int idx){

        if(idx < 0){
            if(target == 0) return 1;
            else return 0;
        }

        int minus = solve(nums, target - (-1 * nums[idx]), idx - 1);
        int plus = solve(nums, target - nums[idx], idx - 1);

        return minus + plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, target, n-1);
    }
};