class Solution {
public:
    string largestOddNumber(string num) {
        int ind = -1;
        int len = num.size();
        for(int i=len-1; i>=0; i--){
            if((num[i]-'0')%2 == 1){
                ind = i;
                break;
            }
        }
        int i = 0;
        while(i<=ind && num[i]=='0') i++;
        return num.substr(i,ind-i+1);
    }
};