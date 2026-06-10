class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m, vector<int>(n,-1));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(auto d: dir){
                int nr = d[0] +r;
                int nc = d[1] + c;
                if(nr<0 || nc<0 || nr>=m || nc>=n || dist[nr][nc] != -1)
                    continue;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr,nc});
            }
        }
        return dist;
    }
};