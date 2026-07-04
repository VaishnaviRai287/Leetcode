class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int distance = road[2];
            graph[u].push_back({v, distance});
            graph[v].push_back({u, distance});
        }
        int min_score = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int current_city = q.front();
            q.pop();
            for (const auto& edge : graph[current_city]) {
                int neighbor = edge.first;
                int distance = edge.second;
                min_score = min(min_score, distance);
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return min_score;
    }
};