class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int size = 0;
        for(char ch: s){
            if(ch == '('){
                if(size>0) res+=ch;
                size++;
            }else if(ch == ')'){
                size--;
                if(size>0) res+=ch;
            }
        }
        return res;
    }
};