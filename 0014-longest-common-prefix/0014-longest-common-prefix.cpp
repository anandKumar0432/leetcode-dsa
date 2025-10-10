class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = "";
        int smallest = INT_MAX;
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            if(str.size() < smallest){
                smallest = str.size();
            }
        }

        for(int i=0; i<smallest; i++){
            string str = strs[0].substr(0,i+1);
            for(int j=0; j<strs.size(); j++){
                if(strs[j].substr(0,i+1) != str){
                    return prefix;
                }
            }
            prefix = str;         
        }
        return prefix;
    }
};