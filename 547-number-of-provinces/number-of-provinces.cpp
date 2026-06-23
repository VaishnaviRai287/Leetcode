class DisjointSet{
vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i<=n ; i++){
            parent[i] = i;
        }
    }
    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }
    void unionbysize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        DisjointSet ds(m);
        for(int i = 0; i<m ; i++){
            for(int j = i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionbysize(i,j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i<m; i++){
            if(ds.findUpar(i) == i){
                cnt++;
            }
        }
        return cnt;
    }
};