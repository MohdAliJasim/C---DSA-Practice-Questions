class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero =0;
        int r = 0;
        int l = 0;
        int ans = 0;
        while(r < nums.size()){
            if(nums[r] == 0) zero++;
            while(zero == 2){
                if(nums[l] == 0) zero--;
                l++;
            }

            ans = max(ans , r-l+1);
            r++;
        }
        return ans-1;
    }
};