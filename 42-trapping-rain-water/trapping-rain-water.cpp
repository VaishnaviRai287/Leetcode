class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;   
        int l = 0;
        int r = n-1;
        int ans = 0;
        int LeftMax = height[l];
        int RightMax = height[r];
        while(l< r){
            if (LeftMax <= RightMax) {
                ++l;
                if (height[l] >= LeftMax) LeftMax = height[l];
                else ans += LeftMax - height[l];
            } else {
                --r;
                if (height[r] >= RightMax) RightMax = height[r];
                else ans += RightMax - height[r];
            }
        }
        return ans;
    }
};