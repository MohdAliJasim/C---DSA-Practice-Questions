class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        for(int i=0 ; i < nums.size();i++){
            sum += nums[i];
        }
        int ans = -1;
        for(int i = nums.size()-1; i>= 0;i--){
            sum -= nums[i];
            if(sum== left) ans = i;
            left += nums[i];
        }
        return ans;
    }
};