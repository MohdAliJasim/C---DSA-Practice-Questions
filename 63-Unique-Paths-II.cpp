class Solution {
public:

    int solve(vector<vector<int>> &obs, int n , int m,vector<vector<int>>& dp){
        if(n == 0 && m == 0) return 1;
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int path1 = 0;
        int path2 = 0;
        if(n >0 && obs[n-1][m] != 1) path1 = solve(obs , n-1, m,dp);
        if(m > 0 && obs[n][m-1] != 1) path2 = solve(obs , n , m-1,dp);

        return dp[n][m] = path1+path2;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1,dp);
    }
};