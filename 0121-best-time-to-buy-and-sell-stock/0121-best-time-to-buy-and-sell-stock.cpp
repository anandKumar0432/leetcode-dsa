// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;

//         for(int i=0; i<prices.size(); i++){
//             for(int j=i+1; j<prices.size(); j++){
//                int localProfit = prices[j] - prices[i];
//                 if(localProfit > profit){
//                     profit = localProfit;
//                 } 
//             }
//         }
//         return profit;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            int cost = prices[i] - mini;
            profit = max(cost, profit);
            
            if(prices[i] < mini) mini = prices[i];
        }

        return profit;
    }
};