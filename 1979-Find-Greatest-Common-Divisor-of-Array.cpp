class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        for(int a : nums){
            maxi = max(maxi , a);
            mini = min(mini, a);
        }
        while(mini != 0 && maxi != 0){
            if(mini > maxi) mini = mini%maxi;
            else maxi = maxi%mini;
        }
        if(maxi == 0) return mini;
        else return maxi;
    }
};