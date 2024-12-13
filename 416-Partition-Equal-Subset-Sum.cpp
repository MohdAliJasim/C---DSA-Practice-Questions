class Solution {
public:
  //  bool dp[20002][100002];
        bool canPartition(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int num : nums) maxi += num;
        if(maxi%2 == 1) return false;
        int target = maxi/2;

        vector<vector<bool>>dp(n+1, vector<bool>(target+1,true));

        for(int i = 0;i < n+1;i++){
            for(int j = 0 ;j < target+1;j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0 && i ==0) dp[i][j] = true;
            }
        }

        for(int i =1 ; i < n+1; i++){
            for(int j = 1 ; j < target+1; j++){

                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j- nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];


    }
};