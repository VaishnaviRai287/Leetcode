class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> dp;
    bool solve(int idx, int jump, vector<int>& stones){
        if(idx == stones.size()-1) return true;
        if(dp[idx][jump] != -1) return dp[idx][jump];
        for(int nextJump = jump-1; nextJump<= jump+1; nextJump++){
            if(nextJump<=0) continue;
            int nextStone = stones[idx] + nextJump;
            if(mp.find(nextStone)!= mp.end()){
                int nextIndex = mp[nextStone];
                if(solve(nextIndex,nextJump, stones)){
                    return dp[idx][jump] = true;
                }
            }
        }
        return dp[idx][jump] = false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        int n = stones.size();
        dp.assign(n, vector<int>(n+1,-1));
        for(int i = 0; i< stones.size(); i++){
            mp[stones[i]] = i;
        }
        return solve(1,1,stones);
    }
};