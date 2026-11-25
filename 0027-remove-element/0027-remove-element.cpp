class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>nums1;
        int k = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != val){
                nums1.push_back(nums[i]);
                k++;
            }
        }
        nums.clear();
        for(int i = 0; i<k; i++){
            nums.push_back(nums1[i]);
        }
        return k;
    }
};