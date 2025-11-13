class Solution {
public:
    // void leftRotate(vector<int> &nums , int index){
    //     for(int i=nums.size()-1; i>index; i+--){
    //         nums[i] = nums[i-1];
    //     }
    // }
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int i = 0;
    //     int j = 0;

    //     while(i < m-n && j < n){
    //         if(nums1[i] <= nums2[j]){
    //             i++;
    //         }else{
    //             leftRotate(nums1, i);
    //             nums1[i] = nums2[j];
    //             j++;
    //         }
    //     }
    // }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<nums2.size(); i++){
            nums1[m] = nums2[i];
            m++;
        }

        sort(nums1.begin(), nums1.end());
    }
};