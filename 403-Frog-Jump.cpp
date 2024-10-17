class Solution {
public:
    bool fn( int index  , int n , vector<int>& stones, int last, vector<vector<int>>& dp){
        if(index == n-1) return true;
        cout << stones[index];
        if(dp[index][last] != -1) return dp[index][last];
        for(int i = index + 1; i < n ; i++){
            if(stones[i] == stones[index] + last -1){  
                if(fn(i , n , stones , last-1,dp)) return true;
            }
            if(stones[i] == stones[index] + last )  {
                if(fn(i , n , stones , last, dp)) return true;
            }
            if(stones[i] == stones[index] + last +1) {
                if(fn(i , n , stones , last +1 ,dp)) return true;
            }
        }
        dp[index][last] = false;
        return false;
    }
    bool canCross(vector<int>& stones) {
        int index = 0 ;
        int n = stones.size();
        int last = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        bool ans = fn(index , n , stones , last, dp);
        return ans;
    }
};