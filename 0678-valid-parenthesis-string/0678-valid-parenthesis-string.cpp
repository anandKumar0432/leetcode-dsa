class Solution {
public:
    // RECURSIVE APPROACH -- TLE

    // bool solve(string& s, int idx, int count, int n){
    //     if(count < 0) return false;
    //     if(idx == n) return count == 0;

    //     if(s[idx] == '('){
    //         return solve(s, idx+1, count+1, n);
    //     }
    //     if(s[idx] == ')') {
    //         return solve(s, idx+1, count-1, n);
    //     }

    //     return solve(s, idx+1, count+1, n) || solve(s, idx+1, count-1, n) || solve(s, idx+1, count, n);
    // }
    


    bool checkValidString(string s) {
        int n = s.size();
        
        int mini = 0;
        int maxi = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                mini += 1;
                maxi += 1;
            }
            if(s[i] == ')') {
                mini -= 1;
                maxi -= 1;
            }
            if(s[i] == '*'){
                mini -= 1;
                maxi += 1;
            }

            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }

        return mini == 0;
    }
};