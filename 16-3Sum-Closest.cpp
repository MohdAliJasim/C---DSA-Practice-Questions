class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int res;
        for(int i = 0 ;i < nums.size()-2; i++){
            for(int j = i+1;j < nums.size()-1;j++){
                for(int k = j + 1; k < nums.size();k++){
                    if(ans >  abs(nums[i]+nums[j]+nums[k] - target)){
                        res = nums[i]+nums[j]+nums[k];
                        ans = min (ans,abs(nums[i]+nums[j]+nums[k] - target));
                    }
                    
                }
            }
        }
        return res;
    }
};