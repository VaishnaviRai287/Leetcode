class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nge;
        int m = nums2.size();
        int n = nums1.size();
        for(int i=m-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) nge[nums2[i]] = -1;
            else nge[nums2[i]] = st.top();
            st.push(nums2[i]);    
        }
        for(int i = 0; i<n; i++){
            nums1[i] = nge[nums1[i]];
        }
        return nums1;
    }
};