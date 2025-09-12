class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int left = INT_MIN;
            int right = INT_MIN;
            if(mid-1 >= 0){
                left = nums[mid-1];
            }
            if(mid+1 < n){
                right = nums[mid+1];
            }

            if(left > nums[mid]){
                end = mid - 1;
            }else if (right > nums[mid]){
                start = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};