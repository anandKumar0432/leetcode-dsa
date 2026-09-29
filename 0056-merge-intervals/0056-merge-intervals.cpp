class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> temp(2,0);
        vector<vector<int>> result;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        for(int i=0; i<n;i++){
            if(result.empty() || result.back()[1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }else{
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }
};