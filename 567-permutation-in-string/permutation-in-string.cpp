class Solution {
public:
    bool isfreqsame(int freq1[], int freq2[]){
        for(int i =0; i<26; i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int s1arr[26] = {0};
        int s2arr[26] = {0};
        for(int i=0; i<s1.length(); i++){
            s1arr[s1[i]-'a']++;
            s2arr[s2[i]-'a']++;
        }
        for(int i =0; i<s2.length() - s1.length(); i++){
            if(isfreqsame(s1arr,s2arr)) return true;
            s2arr[s2[i+s1.length()]-'a']++;
            s2arr[s2[i]-'a']--;
        }
        return isfreqsame(s1arr,s2arr);
    }
};