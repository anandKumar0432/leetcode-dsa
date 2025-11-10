class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int size = nums.size();
        // for(int i=0; i<k; i++){
        //     int temp = nums[size-1];
        //     for(int j=size-2; j>=0; j--){
        //        nums[j+1] = nums[j];
        //     }
        //     nums[0] = temp;
        // } // TLE MAAR GAYA

        vector<int> temp;
        if(k<=nums.size()){
            for(int i=nums.size()-k; i<nums.size(); i++){
            temp.push_back(nums[i]);
            }
            for(int i=0; i<nums.size()-k; i++){
                temp.push_back(nums[i]);
            }
            nums.assign(temp.begin(), temp.end());
        }else{
            for(int i=0; i<k; i++){
                for(int j=nums.size()-1; j>0; j--){
                    swap(nums[j-1] , nums[j]);
                }
            } 
        }
    }
};