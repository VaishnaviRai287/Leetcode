class Solution {
public:
    bool isAlphanumeric(char ch){
        return((ch>= '0' && ch<= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'));
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            if(!isAlphanumeric(s[left])) {left++; continue;}
            if(!isAlphanumeric(s[right])) {right--; continue;}
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};