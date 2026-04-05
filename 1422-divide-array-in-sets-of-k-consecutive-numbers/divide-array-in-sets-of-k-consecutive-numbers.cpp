class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if((nums.size()%k)!=0) return false;
        map<int,int> freq;
        for(int x: nums) freq[x]++;
        for(auto &[num,count]:freq){
            if(count == 0) continue;
            for(int i = 1; i<k; i++){
                auto it = freq.find(num+i);
                if(it==freq.end()||it->second <count) return false;
                it->second -= count;
            }
        }
        return true;
    }
};