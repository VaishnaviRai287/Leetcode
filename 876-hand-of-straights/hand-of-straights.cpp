class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size(); 
        if((size%groupSize) != 0) return false;
        map<int, int> freq;
        for (int x : hand) freq[x]++;

        for (auto &[num, count] : freq) {
            if (count == 0) continue;    
            for (int i = 1; i < groupSize; i++) {
                auto it = freq.find(num + i);
                if (it == freq.end() || it->second < count)
                    return false;
                it->second -= count;
            }
        }
        return true;
    }
};