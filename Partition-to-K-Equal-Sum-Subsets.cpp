class Solution {
public:
    bool solve(vector<int>& nums, int mask, int bucketSum, vector<int>& vis, int index,
               int k, int req, vector<int>& dp) {
        if (k == 0)
            return true;

        if (bucketSum == req) {
            return solve(nums, mask, 0, vis, 0, k - 1, req, dp);
        }

        if (index == nums.size())
            return false;

        pair<int, vector<int>> state = {index, vis};

        if(dp[mask] != -1) return dp[mask];

        bool pick = false;
        if (!(mask & (1 << index)) && nums[index] + bucketSum <= req && !vis[index]) {
            vis[index] = true;
            pick = solve(nums, (mask | (1 << index)), bucketSum + nums[index], vis, index + 1, k, req, dp);
            vis[index] = false;
        }
        bool notpick = solve(nums,mask, bucketSum, vis, index + 1, k, req, dp);
        return dp[mask] = notpick || pick;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        vector<int> vis(nums.size(), 0);
        vector<int> dp(1 << n,-1);
        return solve(nums,0, 0, vis, 0, k, target, dp);
    }
};