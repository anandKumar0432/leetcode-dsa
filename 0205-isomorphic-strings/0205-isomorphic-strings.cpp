class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char, char> mpp1;
        map<char, char> mpp2;
        for(int i=0; i<s.size(); i++){
            char a = s[i];
            char b = t[i];
            if(mpp1.count(a) || mpp2.count(b)){
                if(mpp1[a] != b || mpp2[b] != a){
                    return false;
                }
            }else{
                mpp1[a] = b;
                mpp2[b] = a;
            }
        }
        return true;
    }
};