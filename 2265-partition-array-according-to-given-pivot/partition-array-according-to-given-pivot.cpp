class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> greater;
        vector<int> equal;
        for(int n : nums){
            if(n<pivot){
                smaller.push_back(n);
            }else if(n == pivot){
                equal.push_back(n);
            }else{
                greater.push_back(n);
            }
        }
        smaller.insert(smaller.end(), equal.begin(), equal.end());
        smaller.insert(smaller.end(), greater.begin(), greater.end());
        return smaller;
    }
};