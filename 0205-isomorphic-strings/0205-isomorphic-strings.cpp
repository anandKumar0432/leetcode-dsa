// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.size() != t.size()){
//             return false;
//         }
//         map<char, char> mpp1;
//         map<char, char> mpp2;
//         for(int i=0; i<s.size(); i++){
//             char a = s[i];
//             char b = t[i];
//             if(mpp1.count(a) || mpp2.count(b)){
//                 if(mpp1[a] != b || mpp2[b] != a){
//                     return false;
//                 }
//             }else{
//                 mpp1[a] = b;
//                 mpp2[b] = a;
//             }
//         }
//         return true;
//     }
// };











class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1, mp2;
        if(s.size() != t.size()) return false;

        for(int i=0; i<s.size(); i++){
            if(mp1.find(s[i]) == mp1.end()){
                mp1[s[i]] = t[i];
            }

            if(mp2.find(t[i]) == mp2.end()){
                mp2[t[i]] = s[i];
            }
        }

        for(int i=0; i<s.size(); i++){
            if(mp1[s[i]] != t[i]) return false;
            if(mp2[t[i]] != s[i]) return false;
        }

        return true;

    }
};











