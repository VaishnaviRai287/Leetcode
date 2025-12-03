class Solution {
public:
    long long subArrayMin(vector<int>& nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> pse(n);
        stack<int> ts;
        for(int i = 0; i<n; i++){
            while(!ts.empty() && nums[ts.top()] > nums[i]){
                ts.pop();
            }
            pse[i] = ts.empty() ? -1 : ts.top();
            ts.push(i);
        }

        long long submin;
        for(int i = 0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            submin = (submin + (1LL*left*right*nums[i]));
        }
        return submin;
    }

    long long subArrayMax(vector<int>& nums){
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> pge(n);
        stack<int> ts;
        for(int i = 0; i<n; i++){
            while(!ts.empty() && nums[ts.top()] < nums[i]){
                ts.pop();
            }
            pge[i] = ts.empty() ? -1 : ts.top();
            ts.push(i);
        }

        long long submax;
        for(int i = 0; i<n; i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            submax = (submax + (1LL*left*right*nums[i]));
        }
        return submax;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long min = subArrayMin(nums);
        long long max = subArrayMax(nums);
        return max-min;
    }
};