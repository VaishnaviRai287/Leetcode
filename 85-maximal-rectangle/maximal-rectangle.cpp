class Solution {
public:

    int largestRectangle(vector<int> heights){
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); 
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(matrix[r][c] == '1')
                    height[c] += 1;   
                else
                    height[c] = 0; 
            }
            maxArea = max(maxArea, largestRectangle(height));
        }
    return maxArea;
    }
};