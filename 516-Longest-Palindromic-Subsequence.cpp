class Solution {
public:

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        int n = s2.size();
        int m = s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        reverse(s.begin(),s.end());
        

        for(int i = 1; i < n+1 ; i++){
            for(int j = 1; j < m+1; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};