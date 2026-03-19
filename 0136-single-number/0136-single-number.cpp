// class Solution {
// public:
//     int num = 0;
//     int singleNumber(vector<int>& nums) {

//         for(int i=0; i<nums.size(); i++){
//             num = ( num ^ nums[i]);
//         }
//         return num;
//     }
// };



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums[0];
        for(int i=1; i<nums.size(); i++){
            num = num ^ nums[i];
        }

        return num;
    }
    
};