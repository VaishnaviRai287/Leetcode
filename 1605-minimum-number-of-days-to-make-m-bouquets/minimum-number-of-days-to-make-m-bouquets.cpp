class Solution {
public:

    int possible(vector<int>& bloomDay, int mid, int m, int k){
        int bouquets = 0;
        int cnt = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int total = bloomDay.size();
        if ((long long)m * k > total) return -1;
        int maxi = 0;
        int mini = INT_MAX;
        for(int b: bloomDay){
            maxi = max(maxi,b);
            mini = min(mini,b);
        }
        int low = mini, high = maxi;
        int ans = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid, m, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};