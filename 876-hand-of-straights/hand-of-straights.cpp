class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size(); 
        if((size%groupSize) != 0) return false;
        map<int, int> freq;
        for (int x : hand) freq[x]++;

        for (auto &[num, count] : freq) {
            if (count > 0) {
            for (int i = 1; i < groupSize; i++) {  
            int curr = num + i;
            if (freq.count(curr) == 0 || freq[curr] < count) return false;
            freq[curr] -= count;
        }
        freq[num] = 0; 
    }
        }
        return true;
    }
};