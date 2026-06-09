class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max = LLONG_MIN;
        long long min = LLONG_MAX;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }
        long long sum = max - min;
        sum = sum*k;
        return sum;
    }
};