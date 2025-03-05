class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int num : stones) sum += num;
        int target = sum >> 1;
        vector<vector<int>> dp(stones.size()+1, vector<int>(target+1, 0));

        for(int i = 0;i < stones.size()+1;i++){
            dp[i][0] = 1;
        }

        for(int i =1 ; i < stones.size()+1;i++){
            for(int j = 1;j < target+1;j++){
                if(stones[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-stones[i-1]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        int newTarget =0;
        for(int i= 0 ;i < target+1;i++){
            if(dp[stones.size()][i] != 0) newTarget = i;
        }

        return sum - (newTarget << 1);
    }
};