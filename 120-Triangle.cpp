class Solution {
public:

    int solve(vector<vector<int>>& triangle, int row, int col,vector<vector<int>>&dp){
        if(row == 0) return triangle[0][0];
        if(dp[row][col] != -1) return dp[row][col];
        if(row == col){
            return dp[row][col] = solve(triangle, row-1, col-1,dp) + triangle[row][col];
        }
        else if(col == 0){
            return dp[row][col] = solve(triangle, row-1, col,dp) + triangle[row][col];
        }
        else return dp[row][col] = min(solve(triangle, row-1, col-1,dp) + triangle[row][col],
            solve(triangle, row-1, col,dp) + triangle[row][col]);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int lastCol = triangle[row-1].size();
        int mini = INT_MAX;
       
        for(int i = 0 ;i < lastCol; i++){
            vector<vector<int>> dp(row+1,vector<int>(lastCol+1,-1));
            int ans = solve(triangle, row-1,i,dp);
            mini = min(ans , mini);
        }
        return mini;
    }
};