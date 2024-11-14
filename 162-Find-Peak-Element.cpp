class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[size-1] > nums[size-2]) return size-1;

        int l = 1;
        int h = size-2;
        while( l <= h){
            int mid = (l+h)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            else if(nums[mid] > nums[mid-1]) l = mid + 1;
            else h = mid -1;
        }
         return -1;
    }
   
};