class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        int len = num.size();
        for(int i=len-1; i>=0; i--){
            char ch = num[i];
            if(ch=='9'|| ch=='7'||ch=='5'||ch=='3'||ch=='1'){
                return num.substr(0,i+1);
            }
        }
        return res;
    }
};