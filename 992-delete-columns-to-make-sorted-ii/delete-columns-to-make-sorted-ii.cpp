class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int cnt = 0;
        vector<bool> done(n-1,false);

        for(int i = 0; i<m; i++){
            bool valid = true;

            for(int j = 0; j<n-1; j++){
                if(!done[j] && strs[j][i] > strs[j+1][i]){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                cnt++;
                continue;
            }
            for(int j = 0; j< n-1 ; j++){
                if(!done[j] && strs[j][i] < strs[j+1][i]){
                    done[j] = true;
                }
            }
        }    
        return cnt;
    }
};