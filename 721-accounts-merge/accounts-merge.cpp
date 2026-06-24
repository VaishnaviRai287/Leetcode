class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mailNode;
        DisjointSet ds(n);
        for(int i = 0; i<n; i++){
            for(int j = 1; j< accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailNode.find(mail) == mailNode.end()){
                    mailNode[mail] = i;
                }else{
                    ds.unionBySize(i, mailNode[mail]);
                }
            }
        }
        vector<string> merged[n];
        for(auto& it: mailNode){
            string mail = it.first;
            int node = it.second;
            int parent = ds.findUPar(node);
            merged[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i = 0; i<n; i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            //name
            temp.push_back(accounts[i][0]);
            //mails
            for( auto& mail: merged[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};