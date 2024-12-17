class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int count=1;
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i= 0 ;i < nums.size()-1;i++){
            if(nums[i] != nums[i+1]){
                arr.push_back(nums[i+1]);
                count++;
            }
        }
        for(int i =0 ;i < arr.size();i++){
            nums[i] = arr[i];
        }
        return count;
    }
};