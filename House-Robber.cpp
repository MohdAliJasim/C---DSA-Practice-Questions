class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int num = max(nums[0], nums[1]);
        dp[1] = num;
        for(int i = 2; i < nums.size();i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};