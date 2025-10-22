class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arrS[256] = {0};
        int arrT[256] = {0};
        int n = s.size();
        for(int i=0; i<n; i++){
            if(arrS[s[i]]!=arrT[t[i]]) return false;
            arrS[s[i]] = i+1;
            arrT[t[i]] = i+1;
        }
        return true;
    }
};