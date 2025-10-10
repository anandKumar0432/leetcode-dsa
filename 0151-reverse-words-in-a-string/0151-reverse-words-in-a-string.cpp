class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string word = "";

        for(int i=0; i<s.size(); i++){
            if(s[i] != ' '){
                word = word+s[i];
            }
            if((s[i] == ' ' || i == s.size()-1) && !word.empty()){
                str = " " + word + str;
                word = "";
            }
        }
        str.erase(0,1);        
        return str;
    }
};