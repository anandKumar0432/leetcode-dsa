class Solution {
public:
    int findPivot(vector<int>& nums, int n){
        int l = 0;
        int r = n-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    int binarySearch(vector<int>& nums, int start, int end, int target){
        
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums, n);
        int temp = binarySearch(nums,0,pivot-1, target);
        if(temp != -1){
            return temp;
        }
        temp = binarySearch(nums, pivot, n-1, target);
        return temp;
    }
};