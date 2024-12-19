class Solution {
public:

    long long solve(vector<vector<int>> & grid, int n , int m, vector<vector<int>>&dp){
        if(n == 0 && m == 0) return 0;
        if(n < 0 || m < 0 ) return INT_MAX;

        if(dp[n][m] != -1) return dp[n][m];

        if(n > 0 && m == 0) return dp[n][m] = solve(grid,n-1,m,dp)  +grid[n-1][m];

        else if(m > 0 && n == 0 ) return dp[n][m] = solve(grid,n,m-1,dp) + grid[n][m-1];

        else  return dp[n][m] =  min(solve(grid,n-1,m,dp)+grid[n-1][m], solve(grid,n,m-1,dp)+grid[n][m-1]);
    }


    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));
        return solve(grid, grid.size()-1, grid[0].size()-1,dp) + grid[n-1][m-1];   
    }
};