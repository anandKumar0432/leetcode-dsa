class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<int> temp(2,0);
        vector<vector<int>> result;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        for(int i=0; i<n;i++){
            if(result.empty() || result.back()[1] <= intervals[i][0]){
                result.push_back(intervals[i]);
            }
        }

        return n - result.size();
    }
};