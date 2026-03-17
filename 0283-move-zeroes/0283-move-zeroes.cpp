class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 1;
        int i = 0;
        while(j < nums.size()){
            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }else if(nums[i] == 0 && nums[j] == 0){
                j++;
            }else{
                i++;
                j++;
            }
        }
    }
};



// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();

//         for(int i=0; i<n; i++){
//             if(nums[i] == 0){
//                 count++;
//                 nums.erase(nums.begin() + i);
//             }
//         }

//         while(count){
//             nums.push_back(0);
//             count--;
//         }
//     }
// };