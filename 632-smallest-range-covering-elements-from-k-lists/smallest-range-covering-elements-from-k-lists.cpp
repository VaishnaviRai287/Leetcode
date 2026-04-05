class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>> minHeap;
        int curMax = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            minHeap.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }
        vector<int> res =  {0, INT_MAX};
        while(true){
            auto [val, listIndex, index] = minHeap.top();
            minHeap.pop();
            if(curMax-val < res[1]-res[0]){
                res = {val, curMax};
            }
            if(index+1 == nums[listIndex].size()) break;
            int next = nums[listIndex][index+1];
            minHeap.push({next, listIndex, index+1});
            curMax = max(curMax, next);
        }
        return res;
    }
};