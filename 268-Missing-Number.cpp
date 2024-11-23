class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i= 0; i< nums.size()-1;i++){
            bool flag = false;
            if(nums[i] == i) continue;
            
            for(int j= i+1;j < nums.size();j++){
                if(i == nums[j]){
                    swap(nums[i],nums[j]);
                    flag = true;
                    break;
                }
            }
           // if(nums[i] == nums.size()) continue;
            if(flag == false) return i;
        }
        if(nums[nums.size()-1] != nums.size()-1) return nums.size()-1;
        return nums.size();
    }
};