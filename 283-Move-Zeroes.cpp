class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int size = nums.size()-1;
        while(i <= size){
            if(nums[i] != 0) {
                i++;
                continue;
            }
            else{
                int j = i;
                while(j < size ) {
                    swap(nums[j] , nums[j+1]);
                    j++;
                }
                size--;
            }
        }
    }
};