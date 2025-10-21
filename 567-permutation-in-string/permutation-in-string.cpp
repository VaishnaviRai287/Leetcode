class Solution {
public:
    bool isfreqsame(int freq1[], int freq2[]){
        for(int i =0; i<26; i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1>len2) return false;

        int freq[26] = {0};
        for(int i =0; i<len1; i++){
            freq[s1[i] - 'a']++;
        }
        for(int i =0; i<len2; i++){
            int windind= 0, ind=i;
            int windfreq[26] = {0};
            while(windind<len1 && ind<len2){
                windfreq[s2[ind]- 'a']++;
                windind++; ind++;
            }
            if(isfreqsame(windfreq,freq)) return true;
        }
        return false;
    }
};