class Solution {
public:

    bool solve(vector<int>& nums, int k, int index ,int bucket , int target, int mask,
    vector<int> &dp){
        if(k == 0) return true;

        if(target == bucket){
            return solve(nums,k-1,0,0,target,mask,dp);
        }
        if(index == nums.size()) return false;

        if(dp[mask] != -1) return dp[mask];
        bool pick = false;
        if(!(mask & (1 << index)) && nums[index]+bucket <= target ){
            pick = solve(nums, k , index+1,bucket+nums[index],target, (mask | (1 << index)),dp);
        }
        bool notpick = solve(nums, k , index+1, bucket , target, mask,dp);

        return dp[mask] = pick or notpick;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums) sum+= num;
        if(sum % k != 0 ) return false;
        vector<int>dp(1 << nums.size(), -1);
        return solve(nums, k , 0 , 0, sum/k,0,dp);

    }
};