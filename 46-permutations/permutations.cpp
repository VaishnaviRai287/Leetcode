class Solution {
public:
    void permutations(vector<int>&  nums, vector<int>& ds, vector<vector<int>>& ans, vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i< nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                permutations(nums, ds, ans, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(n,0);
        permutations(nums, ds, ans, freq);
        return ans;
    }
};