class Solution {
public:

    int solve(vector<int>& nums, int n, vector<int>& dp){
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = solve(nums, n-2,dp) + nums[n-1];
        int notPick = solve(nums,n-1,dp);

        return dp[n] = max(pick , notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n+1,-1);
        int firstHouse = solve(nums, n-1,dp);
        nums.erase(nums.begin()+0);
        fill(dp.begin(),dp.end(),-1);
        // vector<int>dp2(n+1,-1);
        n = nums.size();
        int secondHouse = solve(nums,n,dp);
        return max(firstHouse, secondHouse);
    }
};