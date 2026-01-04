class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int row = 0;
        int col = m-1;
        int cnt = 0;
        while(row<n && col>=0){
            if(grid[row][col] < 0){
                cnt += n-row;
                col--;
            }else{
                row++;
            }
        }
        return cnt;
    }
};