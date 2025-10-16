class Solution {
public:
    string rotate(string s){
        for(int i=0; i<s.size()-1; i++){
            swap(s[i], s[i+1]);
        }
        return s;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        if(s == goal){
            return true;
        }

        for(int i=1; i<s.size(); i++){
            s = rotate(s);
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};