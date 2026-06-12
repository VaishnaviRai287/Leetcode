class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == 0) {
                if (!dfs(graph, color, neighbor, -c)) {
                    return false;
                }
            } 
            else if (color[neighbor] == c) {
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(graph, color, i, 1)) {
                return false;
            }
        }
        return true;
    }
};