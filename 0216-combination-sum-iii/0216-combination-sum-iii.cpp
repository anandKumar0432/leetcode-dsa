class Solution {
public:
    void solve(int index, int k, int n, int num[], vector<int> &temp, vector<vector<int>> &res){
        if(n == 0 && temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(index >= 9 || temp.size() >= k || n < 0){
            return;
        }
        temp.push_back(num[index]);
        solve(index+1, k, n-num[index], num, temp, res);
        temp.pop_back();
        solve(index+1, k, n, num, temp, res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int num[9] = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> res;
        int index = 0;
        solve(index, k, n, num, temp, res);
        return res;
    }
};