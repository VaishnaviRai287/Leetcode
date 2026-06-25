class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col==n-1)
                return time;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int newTime=max(time,grid[nr][nc]);
                    if(newTime<dist[nr][nc]){
                        dist[nr][nc]=newTime;
                        pq.push({newTime,{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};