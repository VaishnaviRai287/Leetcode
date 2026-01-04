class Solution {
public:
    int bs(vector<int>& row){
        int low=0, high = row.size()-1;
        int ans = row.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 0) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> ans;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<n; i++){
            int soldier = bs(mat[i]);
            ans.push_back({soldier,i});
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(ans[i].second);
        }
        return res;
    }
};