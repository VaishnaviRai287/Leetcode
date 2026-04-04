class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({arr[i], i});
    }
    vector<int> result(n);
    int rank = 1;
    while (!pq.empty()) {
        auto [val, idx] = pq.top();
        pq.pop();
        result[idx] = rank;
        while (!pq.empty() && pq.top().first == val) {
            result[pq.top().second] = rank;
            pq.pop();
        }
        rank++;
    }
    return result;
    }
};