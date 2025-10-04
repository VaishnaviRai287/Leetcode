class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int right=0, left=0;
        int maxCount=0, maxLength = 0;
        while(right < s.size()){
            freq[s[right]-'A']++;
            maxCount = max(maxCount, freq[s[right]-'A']);
            while((right-left+1)-maxCount > k){
                freq[s[left]-'A']--;
                left++;
            }
            maxLength = max(maxLength, (right-left+1));
            right++;
        }
        return maxLength;
    }
};