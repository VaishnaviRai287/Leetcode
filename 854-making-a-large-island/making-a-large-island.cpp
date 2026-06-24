class DisjointSet {
public:
    vector<int> parent, rank, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int dr[4] = { 1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col] == 0) continue;
                for(int i = 0; i<4; i++){
                    int nr= row+ dr[i];
                    int nc = col + dc[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc] == 1){
                        int nodenum = row*n + col;
                        int adjnode = nr*n + nc;
                        ds.unionBySize(nodenum, adjnode);
                    }
                }
            }
        }
        int mx = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col] == 1) continue;
                set<int> comp;
                for(int i = 0; i<4; i++){
                    int nr = row+ dr[i];
                    int nc = col + dc[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc] == 1){
                        comp.insert(ds.findUPar(nr*n+nc));
                    }
                }
                int size = 1;
                for(auto it: comp){
                    size += ds.size[it];
                }
                mx = max(mx, size);
            }
        }
        for(int k = 0; k<n*n; k++){
            mx = max(mx, ds.size[ds.findUPar(k)]);
        }
        return mx;
    }
};