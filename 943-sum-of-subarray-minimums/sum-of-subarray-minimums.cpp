class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        vector<int> pse(n);
        stack<int> ts;
        for(int i = 0; i<n; i++){
            while(!ts.empty() && arr[ts.top()] > arr[i])
                ts.pop();
            if(ts.empty()) pse[i] = -1;
            else pse[i] = ts.top();
            ts.push(i);
        }

        //main loop
        int total = 0; 
        int mod = (int)1e9+7;
        for(int i =0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total+(1LL*left*right*arr[i])) % mod;
        }  
        return total;     
    }
};