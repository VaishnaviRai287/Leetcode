class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1)
            return false;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[stones[i]] = i;
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[1][1] = true;
        for(int i = 1; i < n; i++){
            for(int jump = 1; jump <= n; jump++){
                if(!dp[i][jump])
                    continue;
                for(int nextJump = jump - 1;
                    nextJump <= jump + 1;
                    nextJump++){
                    if(nextJump <= 0)
                        continue;
                    int nextStone = stones[i] + nextJump;
                    if(mp.count(nextStone))
                        dp[mp[nextStone]][nextJump] = true;
                }
            }
        }
        for(int k = 1; k <= n; k++)
            if(dp[n-1][k])
                return true;
        return false;

    }
};