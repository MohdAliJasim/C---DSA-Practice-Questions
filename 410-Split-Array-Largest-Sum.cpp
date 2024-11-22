class Solution {
public:
    int findAns(vector<int>& nums, int mid){
        int ans = 1;
        int subAns = 0;
        for(int i =0;i < nums.size();i++){
            if(subAns + nums[i] <= mid) subAns += nums[i];
            else{
                ans++;
                subAns = nums[i];
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;
        for(int num : nums){
            low = max(low, num);
            high += num;
        }
        while(low <= high){
            int mid = (low + high)/2;
            int ans = findAns(nums,mid);
            if(ans <= k) high = mid-1;
            else low = mid + 1;
        }
        return low ;
    }
};