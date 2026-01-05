class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> check;
        for(int x:arr){
            if(check.count(x*2)) return true;
            if(x % 2 == 0 && check.count(x/2)) return true;
            check.insert(x);
        }
        return false;

    }
};