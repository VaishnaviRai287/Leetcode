class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = nums[nums.size()-1]- nums[0];
        sum = sum*k;
        return sum;
    }
};