class Solution {
public:
    bool possible(vector<int>& weights, int days, int capacity){
        int usedDays = 1;
        int currLoad = 0;

        for(int w : weights){
            if(w > capacity) return false;  

            if(currLoad + w <= capacity){
                currLoad += w;
            } else {
                usedDays++;
                currLoad = w;
            }
        }
        return usedDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0, maxi = 0;
        for(int w : weights){
            total += w;
            maxi = max(maxi, w);
        }

        int low = maxi, high = total;
        int capacity = total;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(possible(weights, days, mid)){
                capacity = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return capacity;
    }
};