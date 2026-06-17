class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        priority_queue< pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>> 
                        > pq;

        vector<vector<int>> dist(m, vector<int>(n,1e9));
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == m-1 && col == n-1) return effort;
            for(int k = 0; k<4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];
                if(nr>= 0 && nr <m && nc>=0 && nc<n){
                    int maxi = max(abs(heights[nr][nc]-heights[row][col]), effort);
                    if(maxi < dist[nr][nc]){
                        dist[nr][nc] = maxi;
                        pq.push({maxi, {nr, nc}});
                    } 
                }
            }
        }
        return 0;
    }
};