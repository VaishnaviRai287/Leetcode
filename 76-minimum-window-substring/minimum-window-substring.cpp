class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0}, l=0, r=0, sIndex=-1, cnt=0, minLength= INT_MAX;
        int n = s.size(), m = t.size();
        for(int i = 0; i < m; i++) hash[t[i]]++;
        while(r<n){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minLength){
                    minLength = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]==1) cnt--;
                l++;
            }
            r++;
        }

        return (sIndex==-1) ? "" : s.substr(sIndex, minLength);
    }
};