class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadBuy = 0;
        int aheadNotBuy = 0;
        int curBuy = 0;
        int curNotBuy = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            curNotBuy = max(prices[ind] + aheadBuy,aheadNotBuy);
            curBuy = max(-prices[ind] + aheadNotBuy,aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};