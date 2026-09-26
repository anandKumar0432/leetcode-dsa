// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();

//         vector<int> left(n);

//         left[0] = 1;

//         for(int i=1; i<n; i++){
//             if(ratings[i] > ratings[i-1]){
//                 left[i] = left[i-1]+1;
//             }else{
//                 left[i] = 1;
//             }
//         }
//         int sum = 0;
//         int curr = 1;
//         int next = 1;

//         sum = sum + max(curr, left[n-1]);

//         for(int i=n-2; i>=0; i--){
//             if(ratings[i] > ratings[i+1]){
//                 curr = next + 1;
//                 sum = sum + max(curr, left[i]);
//                 next = curr;
//             }else {
//                 curr = 1;
//                 next = curr;
//                 sum = sum + max(curr, left[i]);
//             }
//         }
        
//         return sum;
//     }
// };


// ----------------SLOPE METHOD-----------------

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        int peak;
        int down;
        while(i<n){
            while(i<n && ratings[i] == ratings[i-1]) {
                sum += 1;
                i++;
            }
            peak = 1;

            while(i<n && ratings[i] > ratings[i-1]){
                peak += 1; 
                sum += peak; 
                i++;
            }
            down = 1;
            while(i<n && ratings[i] < ratings[i-1]) {
                sum += down;
                down += 1;
                i++;
            }
            if(down > peak) sum = sum + (down - peak);
        }
        
        return sum;
    }
};