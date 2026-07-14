class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, obstacleGrid, dp);
    }
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i>=0 && j>=0 && mat[i][j] == 1) return dp[i][j] = 0;
        if(i==0 && j==0) return dp[i][j] = 1;

        int up = f(i-1, j, mat, dp);
        int left = f(i, j-1, mat, dp);
        return dp[i][j] = up+left;
    }
};