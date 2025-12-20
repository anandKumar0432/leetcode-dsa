class Solution {
public:
    void solve(int index, string digits, string mapping[], string &output, vector<string> &res){
        if(index >= digits.size()){
            res.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(index+1, digits,mapping, output, res);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int index = 0;
        vector<string> res;
        if(digits.size() == 0){
            return res;
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output = "";
        solve(index, digits, mapping, output, res);
        return res;
    }
};