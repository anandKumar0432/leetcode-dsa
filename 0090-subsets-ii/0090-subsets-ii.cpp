class Solution {
public:
    set<vector<int>> st;
    void sequence(int index, vector<int>& nums, vector<int> &temp, vector<vector<int>> &res){
        if(index >= nums.size()){
            if(st.find(temp) == st.end()){
                st.insert(temp);
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[index]);
        sequence(index+1, nums, temp, res);
        temp.pop_back();
        sequence(index+1, nums, temp, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        int index = 0;
        sort(nums.begin(), nums.end());
        sequence(index, nums, temp, res);
        return res;
    }
};