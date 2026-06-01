class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long cmass = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i =0; i <n; i++){
            if(asteroids[i]>cmass){
                return false;
            }
            cmass += asteroids[i];
        }
        return true;
    }
};