class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int k = nums.size();
        int n = k/2;
        unordered_map<int,int> mpp;
        for(int i = 0; i<k; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>=n){
                return nums[i];
            }
        }
        return -1;
    }
};