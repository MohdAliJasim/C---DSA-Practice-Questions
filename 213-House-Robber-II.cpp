class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return nums[0]>nums[1]?nums[0]:nums[1];
        vector<int>dp1(nums.size()+1, 0);
        vector<int>dp2(nums.size()+1,0);
        dp1[0] = 0;
        dp1[1] = nums[0];
        for(int i = 2 ; i < nums.size();i++){
            dp1[i] = max(dp1[i-2] + nums[i-1], dp1[i-1]);
        }
        dp2[0] = 0;
        dp2[1] = nums[1];
        
        for(int i = 2; i < nums.size();i++){
            dp2[i] = max(dp2[i-2] + nums[i] , dp2[i-1]);
        }
        return max(dp1[nums.size()-1], dp2[nums.size()-1]);
    }
};