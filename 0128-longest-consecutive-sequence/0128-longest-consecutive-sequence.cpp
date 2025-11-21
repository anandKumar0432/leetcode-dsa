class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 0;
        int count = 1;
        if(nums.size() == 1){
            return 1;
        }
        for(int i =1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                count+=1;
            }
            if(nums[i] != nums[i-1]+1 && nums[i] != nums[i-1]){
                count = 0;
                count+=1;
            }
            if(maxi<count){
                maxi = count;
            }
        }
        return maxi;
    }
};