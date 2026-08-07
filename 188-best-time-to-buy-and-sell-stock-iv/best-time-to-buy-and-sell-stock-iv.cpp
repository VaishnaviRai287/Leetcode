class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int count, vector<vector<vector<int>>> & dp) {
        if (ind == prices.size() || count == 0) return 0;
        if(dp[ind][buy][count] != -1) return dp[ind][buy][count];
        if (buy) {
            return dp[ind][buy][count] = max(-prices[ind] + f(ind + 1, 0, prices,count, dp),f(ind + 1, 1, prices,count, dp));
        }
        return dp[ind][buy][count] = max(prices[ind] + f(ind + 1, 1, prices, count -1, dp),f(ind + 1, 0, prices, count, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, prices, k, dp);
    }
};