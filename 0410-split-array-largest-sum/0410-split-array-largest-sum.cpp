class Solution {
public:
    int split(vector<int>& nums, int mid){
        int count = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i] > mid){
                count++;
                sum = nums[i];
            }else{
                sum+=nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        int start = *max_element(nums.begin(), nums.end());
        int end = sum;
        int result;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(split(nums, mid) > k){
                start = mid+1;
            }else{
               result = mid;
               end = mid-1;
            }
        }
        return result;
    }
};