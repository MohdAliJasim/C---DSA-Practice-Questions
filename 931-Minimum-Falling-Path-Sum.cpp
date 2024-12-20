class Solution {
public:

    int solve(vector<vector<int>>& matrix, int row, int col , int colsize, vector<vector<int>> &dp){
        if(row == 0) return matrix[0][col];

        if(dp[row][col] != 1e9) return dp[row][col];
        if(col > 0 && col < colsize){
            int left = solve(matrix, row-1, col-1, colsize,dp) + matrix[row][col];
            int center = solve(matrix, row-1, col , colsize,dp)+ matrix[row][col];
            int right = solve(matrix, row-1, col+1, colsize,dp) + matrix[row][col];
            return dp[row][col] = min(left, min(center, right));
        }

        else if(col == 0){
            int center = solve(matrix, row-1, col , colsize,dp)+ matrix[row][col];
            int right = solve(matrix, row-1, col+1, colsize,dp) + matrix[row][col];
            return dp[row][col] = min(center, right);
        }
        else if(col == colsize){
            int left = solve(matrix, row-1, col-1, colsize,dp) + matrix[row][col];
            int center = solve(matrix, row-1, col , colsize,dp)+ matrix[row][col];
            return dp[row][col] = min(left, center);
        }
        return 0;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        
        for(int i = 0 ; i < m;i++){
            vector<vector<int>>dp(n+1, vector<int>(m+1, 1e9));
            int ans = solve(matrix, n-1, i, m-1,dp);
            mini = min(mini, ans);
        }
        return mini;
    }
};