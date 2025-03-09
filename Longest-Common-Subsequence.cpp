class Solution {
public:

    int solve(string &text1, string &text2, int n , int m, vector<vector<int>> &dp){
        if(n == text1.size() || m == text2.size()) return 0;
        int pick = 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(text1[n] == text2[m]){
            pick = solve(text1, text2, n+1 , m+1,dp) + 1;
        }
        int notpick = max(solve(text1,text2, n+1,m,dp),solve(text1, text2,n , m+1,dp));
        return dp[n][m] = max(pick , notpick);
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,-1));
        return solve(text1 , text2 , 0 , 0, dp);
    }
};