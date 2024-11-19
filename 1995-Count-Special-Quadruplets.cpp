class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt =0 ;
        if(nums.size() < 4) return 0;
        for(int i =0;i < nums.size()-3;i++){
            for(int j = i+1;j<nums.size()-2;j++){
                for(int k = j+1; k < nums.size()-1;k++){
                    for(int m = k+1; m<nums.size();m++){
                        if(nums[i] + nums[j] + nums[k] == nums[m]){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};