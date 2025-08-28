class Solution {
public:
    int myAtoi(string s) {
        int j=0;
        while(j<s.size() && s[j] == ' '){
            j++;
        }

        bool neg = false; 
        long ans = 0;
        for(int i=j; i<s.size(); i++){
            if(i == j){
                if(s[i] == '+'){
                    continue;
                }else if(s[i] == '-'){
                    neg = true;
                    continue;
                }
            }
            if(s[i] >= '0' && s[i] <= '9'){
                ans = 10*ans + (s[i] - '0');
                if(!neg && ans > INT_MAX){
                    return INT_MAX;
                }else if(neg && (-1*ans) < INT_MIN){
                    return INT_MIN;
                }
            }else{
                break;
            }
        }

        if(neg){
            ans = -1 * ans;
        }

        return (int)ans;
    }
};