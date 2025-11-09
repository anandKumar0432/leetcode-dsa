class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int total = 0;

        for(int i=0; i<s.size()-1; i++){
            int curr = mpp[s[i]];
            int next = mpp[s[i+1]];
            if(curr < next){
                total = total-curr;
            }else{
                total = total + curr;
            }
        }
        total = total + mpp[s[s.size()-1]];
        return total;
    }
};