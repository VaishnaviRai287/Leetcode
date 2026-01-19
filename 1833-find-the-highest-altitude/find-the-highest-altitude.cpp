class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = INT_MIN;
        int alt = 0;
        for(int i = 0; i<gain.size(); i++){
            maxi = max(alt,maxi);
            alt = alt + gain[i];  
        }
        maxi = max(alt,maxi);
        return maxi;
    }
};