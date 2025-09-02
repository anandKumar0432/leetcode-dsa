class Solution {
public:
    long long possible(vector<int>& piles, int mid){
        long long count = 0;
        for(int i=0; i<piles.size(); i++){
            count = count + piles[i]/mid;
            if(piles[i]%mid != 0){
                count++;
            }
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int result = -1;
        long long end = *max_element(piles.begin(),piles.end());

        while(start <= end){
            int mid = start + (end-start)/2;
            if(possible(piles, mid) <= h){
                end = mid-1;
                result = mid;
            }else{
                start = mid+1;
            }
        }
        return result;
    }
};