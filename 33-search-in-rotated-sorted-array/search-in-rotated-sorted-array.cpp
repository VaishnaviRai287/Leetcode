class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;

            //left half sorted
            if(nums[mid] >= nums[low]){
                //if in this left half 
                if(nums[low] <= target && target <nums[mid]){
                    high = mid-1;
                }else{
                    //in right half 
                    low = mid+1;
                }
            }//right half sorted
            else{
                if(nums[mid] < target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};