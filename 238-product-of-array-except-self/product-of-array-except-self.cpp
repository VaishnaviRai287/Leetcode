class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int r = nums.size()-1;
        int leftprod = 1;
        int rightprod = 1;
        vector<int> ans(n);
        vector<int> right(n);
        for(int i = r; i>=0; i--){
            right[i] = rightprod;
            rightprod = rightprod*nums[i];
        }
        for(int i = 0; i<=r; i++){
            ans[i] = leftprod*right[i];
            leftprod = leftprod*nums[i];
        }
        return ans;
    }
};