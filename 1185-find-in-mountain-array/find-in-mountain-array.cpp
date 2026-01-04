/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getpeak(MountainArray& mountainArr){
        int n = mountainArr.length();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int el = mountainArr.get(mid);
            int left  = (mid > 0)     ? mountainArr.get(mid - 1) : INT_MIN;
            int right = (mid + 1 < n) ? mountainArr.get(mid + 1) : INT_MIN;
            if (el > left && el > right) {
                return mid;
            }
            else if (left > el) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }

    int bs(MountainArray& mountainArr, int low, int high, int target, bool asc){
        while(low<=high){
            int mid = low + (high-low)/2;
            int el = mountainArr.get(mid);
            if(el == target){
                return mid;
            }
            if (asc) {
                if (el < target) low = mid + 1;
                else high = mid - 1;
            } else {
                if (el < target) high = mid - 1;
                else low = mid + 1;
        }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int high = mountainArr.length()-1;
        int peak = getpeak(mountainArr);
        int left = bs(mountainArr, 0, peak, target, true);
        if(left!= -1){
            return left;
        }
        int right = bs(mountainArr, peak+1, high, target, false);
        if(right!=-1){
            return right;
        }
        return -1;
    }
};