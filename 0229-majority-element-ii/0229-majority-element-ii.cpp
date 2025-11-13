class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         vector<int> res;
         int maj1 = NULL;
         int count1 = 0;
         int maj2 = NULL;
         int count2 = 0;
         int n = nums.size();

         for(int i=0; i<nums.size(); i++){
            if(nums[i] == maj1){
                count1++;
            }else if(nums[i] == maj2){
                count2++;
            }else if(count1 == 0){
                maj1 = nums[i];
                count1++;
            }else if(count2 == 0){
                maj2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
         }

         //verify the result
         int freq1 = 0;
         int freq2 = 0;
         for(int &num : nums){
            if(num == maj1){
                freq1++;
            }else if(num == maj2){
                freq2++;
            }
         }

         if(freq1 > floor(n/3)){
            res.push_back(maj1);
         }
         if(freq2 > floor(n/3)){
            res.push_back(maj2);
         }
         return res;
    }
};