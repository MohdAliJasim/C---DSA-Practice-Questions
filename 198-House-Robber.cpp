class Solution {
public:
    int fn(vector<int>& nums, int index, vector<int> & dp){
        if(index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];
        
        int pick = fn(nums, index+2, dp) + nums[index];

        int notPick = fn(nums, index+1,dp) + 0;

        dp[index] = max(pick ,notPick);
        return dp[index];

    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1 , -1);
        return fn(nums, 0, dp);
    }
};