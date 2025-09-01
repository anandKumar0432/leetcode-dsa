class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());

        while(start <= end){
            int mid = start + (end - start)/2;
            long long sum = 0;
            for(int i=0; i<nums.size(); i++){
                sum+=nums[i]/mid;
                if(nums[i]%mid != 0){
                    sum++;
                }
            }
            if(sum <= threshold){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
};