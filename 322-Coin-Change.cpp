class Solution {
public:

    long long solve(vector<int>& coins , int amount, int n,vector<vector<int>>&dp){
        if(n == 0){
           //if(amount == 0) return 0;
            if(amount%coins[n] == 0) return amount/coins[n];
            return INT_MAX;
        }
        if(dp[amount][n] != -1) return dp[amount][n];
        long long take = INT_MAX;
        if(amount >= coins[n]){
            take= 1+ solve(coins,amount-coins[n],n,dp);
        }
        long long notTake = solve(coins , amount , n-1,dp);
        return dp[amount][n] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1,-1));
        long long ans = solve(coins, amount,coins.size()-1,dp);
        if(ans >= INT_MAX) return -1;
        return ans;
    }
};