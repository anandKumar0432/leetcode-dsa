// class Solution {
// public:
//     set<vector<int>> s;
//     vector<vector<int>> result;
//     void solve(int start, vector<int> &candidates, int target, vector<int> &temp){
//         if(target == 0){
//             if(s.find(temp) == s.end()){
//                 result.push_back(temp);
//             }
//             s.insert(temp);
//             return;
//         }

//         if(start == candidates.size() || target < 0){
//             return;
//         }
        
//         temp.push_back(candidates[start]);
//         solve(start+1, candidates, target-candidates[start], temp);
//         solve(start,candidates, target-candidates[start], temp);
//         temp.pop_back();
//         solve(start+1, candidates, target, temp);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int>temp;
//         solve(0,candidates, target, temp);
//         return result;
//     }
// };


















class Solution {
public:
    void solve(int index, vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &res){
       if(target == 0){
            res.push_back(temp);
            return;
       }
       if(index >= candidates.size() || target < 0){
        return;
       }
       temp.push_back(candidates[index]);
       solve(index, candidates, target-candidates[index], temp, res);
       temp.pop_back();
       solve(index+1, candidates, target, temp, res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        int index = 0;
        solve(index, candidates, target, temp, res);
        return res;
    }
};


















