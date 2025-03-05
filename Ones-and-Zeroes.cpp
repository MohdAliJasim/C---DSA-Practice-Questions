class Solution {
public:

    int solve(vector<pair<int,int>>& arr, int m , int n, int index,
    vector<vector<vector<int>>>&dp){
        if(index == arr.size()) return 0;
        int pick =0;
        if(dp[index][m][n] != -1) return dp[index][m][n];
        if(arr[index].first <= m && arr[index].second <= n){
            pick = solve(arr,m-arr[index].first,n-arr[index].second,index+1,dp) +1;
        }
        int notpick = solve(arr , m , n, index+1,dp);

        return dp[index][m][n] = max(pick , notpick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> arr(strs.size());
        for(int i = 0;i < strs.size();i++){
            int one = 0;
            int zero = 0;
            for(int j = 0 ;j < strs[i].size();j++){
                if(strs[i][j] == '1') one++;
                else zero++;
            }
            arr[i].first = zero;
            arr[i].second = one;
        }
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(arr, m , n, 0 , dp);
    }
};