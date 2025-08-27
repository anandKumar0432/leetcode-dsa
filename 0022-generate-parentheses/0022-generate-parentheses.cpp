class Solution {
public:
    vector<string> result;
    bool valid(string str){
        int temp = 0;
        for(char ch : str){
            if(ch == '('){
                temp++;
            }
            if(ch == ')'){
                temp--;
            }
            if(temp<0){
                return false;
            }
        }
        return temp == 0;
    }
    void solve(string &str , int &n){
        if(str.size() == 2*n){
            if(valid(str)){
                result.push_back(str);
            }
            return;  
        }

        str.push_back('(');
        solve(str, n);
        str.pop_back();
        str.push_back(')');
        solve(str,n);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return result;
    }
};