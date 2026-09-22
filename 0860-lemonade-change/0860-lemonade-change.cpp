class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;
        int countFive = 1;
        int countTen = 0;
        int countTwenty = 0;

        for(int i=1; i<bills.size(); i++){
            if(bills[i] == 5){
                countFive++;
            }else if(bills[i] == 10){
                if(countFive == 0) return false;
                countFive--;
                countTen++;
            } else {
                if(countTen == 0) {
                    if(countFive < 3) return false;
                    countFive -= 3;
                }
                else if(countTen > 0 && countFive > 0){
                    countTen--;
                    countFive--;
                } else if(countTen > 0 && countFive < 1) return false;
            }
        }

        return true;
    }
};