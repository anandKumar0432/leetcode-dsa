class Solution {
public:
    void solve(vector<vector<int>> &result, vector<int> &nums, vector<bool> &visited, vector<int> temp){

        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
           if(visited[i] == 0){
            visited[i] = 1;
            temp.push_back(nums[i]);
            solve(result, nums, visited, temp);
            temp.pop_back();
            visited[i] = 0;
           }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), 0);

        solve(result, nums, visited, temp);
        return result;
    }
};