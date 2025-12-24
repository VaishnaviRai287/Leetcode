class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalapples = 0;
        for(int i=0; i<apple.size(); i++){
            totalapples += apple[i];
        }

        sort(capacity.begin(), capacity.end());
        int boxes = 0;
        int sum = 0;
        for(int i = capacity.size()-1; i>=0; i--){
            sum += capacity[i];
            boxes++;
            if(sum>=totalapples) break;
        }
        return boxes;
    }
};