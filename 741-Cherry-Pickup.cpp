class Solution {
public:

    int solve(vector<vector<int>>& grid, int i1, int i2 , int j1, int j2, int n,vector<vector<vector<vector<int>>>>&dp){
        if(i1 == n-1 && i2== n-1 && j1 == n-1 && j2 == n-1){
            int ans = grid[n-1][n-1];
            return ans;
        } 
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n ) return -1e8;
        
        if(dp[i1][i2][j1][j2] != -1) return dp[i1][i2][j1][j2];

        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e8;
        
        
        if(i1 == i2 && j1 == j2){
            int val = grid[i1][j1];  
            int ans1= solve(grid, i1+1, i2+1, j1 , j2, n,dp) + val;
            int ans2 = solve(grid , i1 , i2, j1 +1, j2 +1,n,dp) + val;
            int ans3 = solve(grid, i1+1, i2, j1, j2+1,n,dp) + val;
            int ans4 = solve(grid, i1 , i2+1, j1+1, j2,n,dp)+ val;
            return dp[i1][i2][j1][j2] = max(ans1 , max(ans2 , max(ans3, ans4)));
        }
        else{
            int val = grid[i1][j1] + grid[i2][j2];
            int ans1= solve(grid, i1+1, i2+1, j1 , j2, n,dp) + val;
            int ans2 = solve(grid , i1 , i2, j1 +1, j2 +1,n,dp) + val;
            int ans3 = solve(grid, i1+1, i2, j1, j2+1,n,dp) + val ;
            int ans4 = solve(grid, i1 , i2+1, j1+1, j2,n,dp)+ val;
            return dp[i1][i2][j1][j2] = max(ans1 , max(ans2 , max(ans3, ans4)));
        }

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1 , vector<int>(n+1 ,-1))));
        int ans1 =  solve(grid, 0, 0, 0,0, n,dp);
        if(ans1 < 0) return 0;
        return ans1 ;

    }
};