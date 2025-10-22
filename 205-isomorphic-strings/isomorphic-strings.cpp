class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        unordered_map<char,char> mpp1;
        if(s.size()!=t.size()) return false;
        for(int i=0; i<s.size(); i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]] != t[i]) return false;
            }else{
                if(mpp1.count(t[i])) return false;
            }
            mpp[s[i]] = t[i];
            mpp1[t[i]] = s[i];
        }
        return true;
    }
};