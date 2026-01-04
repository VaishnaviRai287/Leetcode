class Solution {
public:
    int divisor(int n){
        int cnt = 0, sum =0;
        for(int i = 1; i*i<=n; i++){
            if(n%i==0){
                cnt+=1;
                sum += i;
                if(n/i != i){
                    cnt+=1;
                    sum += n/i;
                }
                if(cnt > 4) return 0;
            }
        }
        return (cnt == 4) ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+= divisor(nums[i]);
        }
        return sum;
    }
};