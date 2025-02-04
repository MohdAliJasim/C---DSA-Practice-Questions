class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;
        int r = 1, l =0;
        sum = nums[0];
        maxi = sum;
        while(r < nums.size()){
            if(nums[r] > nums[r-1]){
                sum += nums[r];
                maxi = max(maxi,sum);
            }
            else{
                sum = nums[r];
                l = r;
            }
            r++;
        }
        return maxi;
    }
};