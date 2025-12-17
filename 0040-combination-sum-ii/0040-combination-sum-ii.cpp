class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> s;

    void solve(int start, vector<int> &candidates, int target, vector<int> &temp ){
        if(target == 0){
            if(s.find(temp) == s.end()){
                result.push_back(temp);
            }
            s.insert(temp);
            return;
        }

        if(start == candidates.size() || target < 0){
            return;
        }

        for(int i = start; i<candidates.size(); i++){
            if(i>start && candidates[i] == candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i], temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0,candidates,target, temp);
        return result;
    }
};