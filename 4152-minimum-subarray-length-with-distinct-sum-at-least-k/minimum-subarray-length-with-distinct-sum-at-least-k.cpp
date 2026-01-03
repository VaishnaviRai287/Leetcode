class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int l = 0, sum = 0;
        unordered_map<int,int> mpp;
        int ans = INT_MAX;
        for(int r = 0; r<nums.size(); r++){
            if(mpp[nums[r]] == 0){
                sum += nums[r];
            }
            mpp[nums[r]]++;
            while(sum >=k){
                ans = min(ans, r-l+1);
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    sum -= nums[l];
                }
                l++;
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};