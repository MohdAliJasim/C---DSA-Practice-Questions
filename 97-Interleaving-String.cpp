class Solution {
public:
    bool check1(string s1 , string s2 , string s3){
        int  j = 0 , k = 0;
        for(int i = 0;i < s3.size();i++){
            if(k < s2.size() && s3[i] == s2[k]){
                k++;
                continue;
            }
            if(j < s1.size() && s3[i] == s1[j]){
                j++;
                continue;
            }
            return false;
        }
        if(k != s2.size() || j != s1.size()) return false;
        return true;
    }

    bool check2(string s1, string s2, string s3){
         int  j = 0 , k = 0;
        for(int i = 0;i < s3.size();i++){
            if(j < s1.size() && s3[i] == s1[j]){
                j++;
                continue;
            }
            if(k < s2.size() && s3[i] == s2[k]){
                k++;
                continue;
            }
            return false;
        }
        if(k != s2.size() || j != s1.size()) return false;
        return true;
    }

    bool solve(string&s1, string &s2, string&s3, int i , int j , int k,vector<vector<vector<int>>> &dp){
        if(k == s3.size()){
            if(i == s1.size() && j == s2.size()){
                return true;
            }
            return false;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(s1[i] == s2[j]){
            if(s1[i] != s3[k]) return false;
            bool pick1 = solve(s1, s2, s3, i+1,j ,k+1,dp);
            bool pick2 = solve(s1,s2,s3,i, j+1, k+1,dp);
            return dp[i][j][k] = pick1 || pick2;
        }

        else if(s1[i] == s3[k]){
            return dp[i][j][k] = solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        else if(s2[j] == s3[k]){
            return dp[i][j][k] = solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        else{
            return dp[i][j][k] = false;
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1,-1)));
       return solve(s1, s2,s3,0,0,0,dp);
    }
};


























