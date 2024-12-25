class Solution {
public:

    int solve(vector<int>& coins, int amount , int n, vector<vector<int>>& dp){
        if(n== 0){
            if(amount%coins[0] == 0) return 1; 
            else return 0;
        }
        if(dp[amount][n] != -1) return dp[amount][n];
        int pick = 0;
        int notPick = 0;
        if(amount >= coins[n]){
            pick = solve(coins, amount-coins[n],n,dp);
        }
        notPick = solve(coins, amount , n-1,dp);
        return dp[amount][n] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(amount+1 , vector<int>(coins.size()+1, -1));

        return solve(coins, amount, coins.size()-1,dp);
    }
};