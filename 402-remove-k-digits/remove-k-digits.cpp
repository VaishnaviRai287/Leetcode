class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char c : num){
            while(!st.empty() && k>0 && st.back()>c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }
        int idx = 0;
        while(idx<st.size() && st[idx] == '0'){
            idx++;
        }
        st = st.substr(idx);
        return st.empty() ? "0" :st;
    }
};