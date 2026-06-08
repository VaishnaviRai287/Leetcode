class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color)
            return image;
        dfs(sr, sc, image, oldColor, color);
        return image;
    }
    void dfs(int r, int c, vector<vector<int>>& image,
        int oldColor, int newColor) {

        int rows = image.size();
        int cols = image[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols)
            return;

        if(image[r][c] != oldColor)
            return;

        image[r][c] = newColor;

        dfs(r + 1, c, image, oldColor, newColor);
        dfs(r - 1, c, image, oldColor, newColor);
        dfs(r, c + 1, image, oldColor, newColor);
        dfs(r, c - 1, image, oldColor, newColor);
    }
};
