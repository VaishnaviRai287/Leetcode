class Solution {
public:
    int possibly(vector<int>& piles, int k, int h){
        long long hours = 0;
        for(int p:piles){
            hours += (p+k-1)/k;
        }
        if(hours<=h){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = piles[0];
        for (int p : piles) {
            high = max(high, p);
        }
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(possibly(piles,mid,h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};