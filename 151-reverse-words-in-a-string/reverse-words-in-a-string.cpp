class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        string temp = "";
        string ans = "";
        while(left < s.length()){
            char ch = s[left];
            if(ch!= ' '){
                temp+=ch;
            }else if(ch == ' '){
                if(temp.length()>0){
                    if(ans != "") ans = temp + ' ' + ans;
                    else ans = temp;
                    temp = "";
                }
            }
            left++;
        }
        if(temp!=""){
            if(ans != "") ans = temp + ' ' + ans;
            else ans = temp;
        }
        return ans;
    }
};