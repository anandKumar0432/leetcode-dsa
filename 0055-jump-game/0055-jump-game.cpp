class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;

        int maxi = 0;
        int i = 0;
        while(i < nums.size()){
            if(i > maxi)
                return false;
            maxi = max(maxi, i+nums[i]);
            i++;    
        }

        return true;;
    }
};