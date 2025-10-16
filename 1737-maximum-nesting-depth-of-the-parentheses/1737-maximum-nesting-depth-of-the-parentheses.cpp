class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int localMax = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                localMax += 1;
            }
            if(s[i] == ')'){
                localMax -= 1;
            }

            if(localMax > max){
                max = localMax;
            }
        }

        return max;
    }
};