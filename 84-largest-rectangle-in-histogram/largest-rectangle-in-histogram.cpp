class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i =0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        vector<int> nse(n);
        stack<int> ts;
        for(int i=n-1; i>=0; i--){
            while(!ts.empty() && heights[ts.top()] >= heights[i]){
                ts.pop();
            }
            nse[i] = ts.empty() ? n : ts.top();
            ts.push(i);
        }
        int maxi = 0;
        for(int i =0; i<n; i++){
            int space = heights[i]*(nse[i]- pse[i]-1);
            maxi = max(maxi, space);
        }

        return maxi;
    }
};