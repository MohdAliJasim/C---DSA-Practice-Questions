class Solution {
public:
    int change(int sum, vector<int>& coins) {
     
        vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1, 0));
        
        for(int i = 0 ;i < coins.size()+1;i++){
            dp[i][0] = 1;
        }
     
        
        for(int i =1 ;i < coins.size()+1;i++){
            for(int j = 1;j < sum+1;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.size()][sum];
    }
    
};