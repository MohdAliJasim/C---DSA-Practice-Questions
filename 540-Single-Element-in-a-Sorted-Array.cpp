class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 1;
        int h = nums.size()-1;
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[h] != nums[h-1]) return nums[h];
        h--;
        while(l <= h){
            int mid= (l+h) >> 1;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if((mid&1 && nums[mid-1] != nums[mid]) || (!(mid&1) && nums[mid+1] != nums[mid])) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};