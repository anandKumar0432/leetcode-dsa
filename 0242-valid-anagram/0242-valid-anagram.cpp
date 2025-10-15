class Solution {
public:
    bool isAnagram(string s, string t) {
       const int MAX_CHAR = 26;
       int charCount[MAX_CHAR] = {0};

       if(s.length() != t.length()){
        return false;
       }
       
       for(int i = 0; i<s.length(); i++){
        charCount[s[i] - 'a']++;
       }

       for(int i = 0; i<s.length(); i++){
        charCount[t[i] - 'a']--;
       }

       for(int i = 0; i<MAX_CHAR; i++){
        if(charCount[i] != 0){
            return false;
        }
       }
       return true;
    }
};