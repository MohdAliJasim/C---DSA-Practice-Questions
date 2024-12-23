class Solution {
public:

    int my_gcd(int max, int min){
        if(max == 0) return min;
        
        if(min > max){
            swap(min,max);
        }

        return my_gcd(max%min, min);
    }

    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0;i < nums.size();i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini , nums[i]);
        }

        return my_gcd(maxi, mini);
    }
};