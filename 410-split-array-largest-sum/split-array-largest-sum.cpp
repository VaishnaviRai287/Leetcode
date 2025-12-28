class Solution {
public:
    bool cansplit(vector<int>& nums, int k, int mid){
        int count = 1;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            if((sum+nums[i])>mid){
                count++;
                sum = nums[i];
                if(count>k) return false;
            }
            else{
                sum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        int high = 0, low = 0;
        for(int n: nums){
            low = max(low,n);
            high += n;
        }
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(cansplit(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};