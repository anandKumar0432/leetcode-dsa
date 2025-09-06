class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size()-1;
        int res = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            long long miss = arr[mid]-(mid+1);
            if(miss < k){
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }
        return k+end+1; // or we can say low = end+1;
    }
};