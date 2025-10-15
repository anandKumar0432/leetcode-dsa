class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char, int> mpp;

        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>> vecOfMap (mpp.begin(), mpp.end());
        
        sort(vecOfMap.begin(), vecOfMap.end(), [](const pair<char,int> &a, const pair<char,int> &b) {
            return a.second > b.second;
        });

        string str = "";
        for(const auto &pair : vecOfMap){
            str.append(pair.second, pair.first);
        }

        return str;
    }
};