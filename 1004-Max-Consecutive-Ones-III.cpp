class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi =0;
        int l =0;
        int r =0;
        int zero= 0;
        while( r < nums.size()){
            if(nums[r] == 0) zero++;
            if(zero>k){
                if(nums[l] == 0) zero--;
                l++;
            }
            r++;
            if(zero <= k) maxi = max(maxi, r-l);
            
        }
        return maxi;
    }
};