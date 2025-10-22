class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string second = strs[strs.size()-1];
        int len = min(first.size(), second.size());
        int ind = -1;
        for(int i=0; i<len; i++){
            if(first[i]!=second[i]) break;
            ind = i;
        }
        return first.substr(0,ind+1);
    }
};