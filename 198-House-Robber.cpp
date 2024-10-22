class Solution {
public:
// Memoization
    // int fn(vector<int>& nums, int index, vector<int> & dp){
    //     if(index >= nums.size()) return 0;

    //     if(dp[index] != -1) return dp[index];
        
    //     int pick = fn(nums, index+2, dp) + nums[index];

    //     int notPick = fn(nums, index+1,dp) + 0;

    //     dp[index] = max(pick ,notPick);
    //     return dp[index];

    //  int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size()+1 , -1);
    //     return fn(nums, 0, dp);
    // }
    // }


//Tabulation
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size());
//         dp[0] = nums[0];
//         int neg = 0;
//         for(int i = 1 ;i < nums.size();i++){
//             int pick = nums[i]; if(i > 1) pick += dp[i-2];
//             int notPick = 0 + dp[i-1];
//             dp[i] = max(pick , notPick);
//         }
//         return dp[nums.size()-1];
//     }
//

//Space Optimization

int rob(vector<int>& nums){
    int prev = nums[0];
    int beforePrev = 0;
    for(int i =1 ;i < nums.size();i++){
        int pick = nums[i] + beforePrev;
        int notPick = prev;
        int curr = max(pick , notPick);
        beforePrev = prev;
        prev = curr;
    }
    return prev;
}

 };















