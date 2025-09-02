class Solution {
public:
    int checkBloom(vector<int>& bloomDay,int mid, int k){
        int count = 0;
        int bouquetCount = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
            }else{
                count = 0;
            }
            if(count==k){
                bouquetCount++;
                count=0;
            }
        }
        return bouquetCount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 1;
        int result = -1;
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        while(start <= end){
            int mid = start + (end-start)/2;
            if(checkBloom(bloomDay, mid, k) >= m){
                end = mid-1;
                result = mid;
            }else{
                start = mid+1;
            }
        }
        return result;
    }
};