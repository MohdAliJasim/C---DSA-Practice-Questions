class Solution {
public:
    int findThreshold(vector<int>& nums, int mid){
        int ans = 0;
        for (int i = 0;i < nums.size();i++){
            ans += ceil(double(nums[i])/double(mid));
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MIN;
        for(int it : nums) high = max(high ,it);
        while(low <= high){
            int mid = low + (high - low)/2;
            int res = findThreshold(nums, mid);
            if(res <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};