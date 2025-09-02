class Solution {
public:
    int checkCapacity(vector<int>& weights, int mid){
        int count = 1;
        long long sum = 0;
        for(int i=0; i<weights.size(); i++){
            sum+=weights[i];
            if(sum > mid){
                count++;
                sum = weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int result = -1;
        for(int i=0; i<weights.size(); i++){
            sum = sum+weights[i];
        }
        int start = *max_element(weights.begin(), weights.end());
        int end = sum;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(checkCapacity(weights, mid) <= days){
                result = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return result;
    }
};