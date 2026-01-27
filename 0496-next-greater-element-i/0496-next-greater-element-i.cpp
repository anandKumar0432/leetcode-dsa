class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0; i<nums1.size(); i++){
            int dig = nums1[i];
            auto it = find(nums2.begin(), nums2.end(), dig);
            int idx = distance(nums2.begin(), it);
            int n = res.size();
            for(int j=idx+1; j<nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    res.push_back(nums2[j]);
                    break;
                }
            }
            if(n == res.size())
                res.push_back(-1);
        }
        return res;
    }
};