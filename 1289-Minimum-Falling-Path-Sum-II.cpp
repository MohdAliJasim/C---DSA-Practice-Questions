class Solution {
public:
    int solve(vector<vector<int>>& grid , int row , int col,int n, vector<vector<int>>& dp){
        if(row < 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int mini = INT_MAX;
        for(int i = 0 ;i < n ; i++){  
            if(i != col){
                int ans = solve(grid , row-1 , i , n,dp) + grid[row][i];
                mini = min(ans , mini);
            } 
           
        }
         return dp[row][col] = mini;

    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i = 0 ;i < n; i++){
            int ans = solve(grid , n-2,i,n,dp) + grid[n-1][i];
            mini = min(mini , ans);
        }   
        return mini;
    }
};