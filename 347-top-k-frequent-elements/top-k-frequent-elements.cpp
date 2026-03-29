class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num: nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minH;
        for(auto &it: freq){
            minH.push({it.second, it.first});
            if(minH.size()>k){
                minH.pop();
            }
        }
        vector<int> res;
        while(!minH.empty()){
            res.push_back(minH.top().second);
            minH.pop();
        }
        return res;
    }
};