class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        k = k % totalElements; 
        if (k == 0) return grid;
        vector<vector<int>> result(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int flatIndex = i * n + j;
                int shiftedFlatIndex = (flatIndex + k) % totalElements;
                int newI = shiftedFlatIndex / n;
                int newJ = shiftedFlatIndex % n;
                result[newI][newJ] = grid[i][j];
            }
        }
        
        return result;
    }
};