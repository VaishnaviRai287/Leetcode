class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0; 
        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int nottake = prev1; 
            int curr = max(take, nottake);
            prev2 = prev1; 
            prev1 = curr;  
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};