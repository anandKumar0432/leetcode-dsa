// class Solution {
// public:
//     vector<vector<string>> result;
//     bool isPalindrome(vector<string> str){
//         int i, j = 0;
//         while(i<j){
//             if(str[i] == str[j]){
//                 i++;
//                 j++;
//             }else{
//                 return true;
//             }
//         }
//         return true;
//     }
//     void solve(vector<string> &str, int start, vector<string> &temp){
//         if(isPalindrome(temp)){
//             result.push_back(temp);
//         }

//         if(start == str.size()){
//             return;
//         }

//         temp.push_back(str[start]);
//         solve(str, start+1, temp);
//         temp.pop_back();
//         solve(str, start, temp);
//     }
//     vector<vector<string>> partition(string s){
//         vector<string> str;
//         for(int i=0; i<str.size(); i++){
//             str.push_back(string(1, s[i]);
//         }
//         solve(str, 0, temp);
//         return result;
//     }
// };




















class Solution {
public:
    bool isPalindrome(string s, int start ,int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void solve(int index, string s, vector<string> &path, vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s){
        vector<string> path;
        vector<vector<string>> res;
        int index = 0;
        solve(index, s, path, res);
        return res;
    }
};














