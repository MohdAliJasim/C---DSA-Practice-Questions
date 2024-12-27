class Solution {
public:

    int solve(vector<int>& nums , int n , int target,int sum){
        if(n == 0){
            if(sum + nums[0] == target && sum - nums[0] == target) return 2;
            if(sum + nums[0] == target || sum - nums[0] == target) return 1;
            return 0;
        }

        int plus = solve(nums, n-1, target, sum + nums[n]);
        int minus = solve(nums, n-1, target , sum - nums[n]);
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, n-1, target,0);
    }
};